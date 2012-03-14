#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "EasyBMP.h"

#include "structs.h"
#include "vector.h"
#include "pixel.h"
#include "eye.h"
#include "ray.h"
#include "primitive.h"
#include "scene.h"

// Welt-Konstanten
// Werden (später) zur Ausrichtung und platzierung verschiedener Objekte verwendet
#define WORLD_W 200
#define WORLD_H 200
#define WORLD_D 800

// Bild-Konstanten
#define PICTURE_W 1024
#define PICTURE_H 768
// Abstand Augpunkt <-> Bildebene
#define BW 1000

#define MAX_DISTANCE 10000

// Raytracing-Hauptfunktion
Color raytrace(Ray * ray, Scene * scene);
// Nächstes Primitiv finden
void findNextPrimitive(Ray * ray, Scene * scene, float maxDistance, Primitive &nextPrimitive, int &hit);

int main (int argc, char * const argv[]) {
	printf("\n[ Ray Boy ]\n\n");
	
	Eye* eye;
	eye = new Eye;
	eye->setPosition(PICTURE_W/2, PICTURE_H/2, -BW);
	Scene* scene;
	scene = new Scene;
	
	// Szene erstellen
	// Rote Kugel - Körper
	Primitive* sphere1;
	sphere1 = new Primitive;
	sphere1->setColor(255,0,0);
	sphere1->setCenter(512, 384, 200);
	sphere1->setRadius(100);
	scene->addPrimitive(sphere1);
	// Grüne Kugel - linker Fuß
	Primitive* sphere2;
	sphere2 = new Primitive;
	sphere2->setColor(0,255,0);
	sphere2->setCenter(490, 284, 200);
	sphere2->setRadius(50);
	scene->addPrimitive(sphere2);
	// Blaue Kugel - rechter Fuß
	Primitive* sphere3;
	sphere3 = new Primitive;
	sphere3->setColor(0,0,255);
	sphere3->setCenter(534, 284, 200);
	sphere3->setRadius(50);
	scene->addPrimitive(sphere3);
	// Weiße Kugel - Kopf
	Primitive* sphere4;
	sphere4 = new Primitive;
	sphere4->setColor(255,255,255);
	sphere4->setCenter(512, 484, 200);
	sphere4->setRadius(60);
	scene->addPrimitive(sphere4);
	Ray* ray;
	ray = new Ray;
	
	printf(":: objects created\n");
	
	// Bildschirm
	BMP targetImage;
	targetImage.SetSize(PICTURE_W, PICTURE_H);
	targetImage.SetBitDepth(24);
	Pixel* that;
	that = new Pixel;
	
	printf(":: picture initialised\n");
	
	// Für jedes Pixel ein Ray losschicken
	//int temp = 0;
	for (int x = 0; x < PICTURE_W; x++)
	{
		for (int y = 0; y < PICTURE_H; y++)
		{
			ray->setOrigin(eye->getPosition());
			that->setPosition(x+1,y+1,0);
			ray->setDirection(that->getPosition() - eye->getPosition());
			ray->getDirection().Normalize();
			try
			{
				that->color = raytrace(ray, scene);
			}
			catch (const char* ex)
			{
				that->color.r = 255;
				that->color.g = 0;
				that->color.b = 0;
			}
			// BMP-Bilder sind horizontal gespiegelt
			targetImage(x,PICTURE_H-1-y)->Red = that->color.r;
			targetImage(x,PICTURE_H-1-y)->Green = that->color.g;
			targetImage(x,PICTURE_H-1-y)->Blue = that->color.b;
			// Todo: ProzessIndikator
			//if (temp == 0) printf(":: debug\n"); temp++;
			//temp++;
		}
	}

	printf(":: rendered\n");
	targetImage.WriteToFile("/Users/julian/img.bmp");
	printf(":: picture written\n");
	printf(":: finished\n");
    return 0;
}

// Der Raytracing-Part
Color raytrace (Ray * ray, Scene * scene)
{
	// 1. Nächsten Schnittpunkt berechnen
	Primitive nextPrimitive;
	int hit;
	findNextPrimitive(ray, scene, MAX_DISTANCE, nextPrimitive, hit);	
	// 2. Todo: Shading
	return nextPrimitive.getColor();
};

// Nahestes Primitiv finden
void findNextPrimitive (Ray * ray, Scene * scene, float maxDistance, Primitive &nextPrimitive, int &hit)
{
	
	/* PseudoCode
	 Für jedes Primitiv der Szene
		Schnittpunkt = Teste_Primitiv(Primitiv, Strahl)
		Wenn Schnittpunkt.Distanz < MaxDistanz dann
			MaxDistanz = Schnittpunkt.Distanz
			Schnittpunkt.Gewinner = Primitiv
	*/
	
	int intersection = 0;
	double distance = 0;
	nextPrimitive.setColor(0,0,0);
	
	for (int i = 0; i <= scene->getPrimitivesCount(); i++)
	{
		distance = scene->getPrimitive(i)->getIntersection(ray, maxDistance);
		if (distance != 0 && distance <= maxDistance)
		{
			maxDistance = distance;
			intersection = 1;
			nextPrimitive.setColor(scene->getPrimitive(i)->getColor().r, scene->getPrimitive(i)->getColor().g, scene->getPrimitive(i)->getColor().b);
		}
		hit = intersection;
	};

};