#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource& managedResource;

public:
    ResourceManager() : managedResource(*new Resource)
    {
        std::cout << this << "\n Podstawowy konstruktor \n";
    }

    /*
    ResourceManager(Resource& resource) : managedResource(resource)
    {

        //.allocateResources();
    }
    */

    // konstruktor kopiujący
    ResourceManager(const ResourceManager& manager)
        : managedResource(*new Resource = manager.managedResource)
    {
        std::cout << this << "\n Kopiujący konstruktor \n";
    };

    // konstruktor przenoszący
    ResourceManager(ResourceManager&& manager) : managedResource(manager.managedResource) {}

    ~ResourceManager()
    {
        std::cout << this << "\n  Destruktor  \n";
        delete &managedResource;
        //.freeResources();
    }

    // Kopiujący operator przypisania
    ResourceManager& operator=(const ResourceManager& t)
    {
        std::cout << this << "\n Kopiujący operantor przenoszenia \n";
        managedResource = t.managedResource;
        return (*this);
    };
    // Przenoszący operator przypisania
    ResourceManager& operator=(ResourceManager&&);

    double get() { return (managedResource.get()); }
};