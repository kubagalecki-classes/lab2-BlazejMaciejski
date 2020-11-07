#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource managedResource;

public:
    ResourceManager() : managedResource(*new Resource) {}

    /*
    ResourceManager(Resource& resource) : managedResource(resource)
    {

        //.allocateResources();
    }
    */

    // konstruktor kopiujący
    ResourceManager(const ResourceManager& manager) : managedResource(manager.managedResource){};

    // konstruktor przenoszący
    ResourceManager(ResourceManager&& manager) : managedResource(manager.managedResource) {}

    ~ResourceManager()
    {
        delete &managedResource;
        //.freeResources();
    }

    // Kopiujący operator przypisania
    ResourceManager& operator=(const ResourceManager& t) { managedResource = t.managedResource; };
    // Przenoszący operator przypisania
    ResourceManager& operator=(ResourceManager&&);

    double get() { return (managedResource.get()); }
};