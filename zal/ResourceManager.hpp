#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource& managedResource;

public:
    ResourceManager(Resource& resource) : managedResource(resource)
    {

        //.allocateResources();
    }

    ~ResourceManager()
    {
        delete &managedResource;
        //.freeResources();
    }

    // Przenoszący operator przypisania
    ResourceManager& operator=(ResourceManager&&);

    double get() { return (managedResource.get()); }
};