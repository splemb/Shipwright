#pragma once

#include "Resource.h"
#include "ResourceFactory.h"

namespace Ship {
class SkeletonLimbFactory : public ResourceFactory
{
  public:
    std::shared_ptr<Resource> ReadResource(uint32_t version, std::shared_ptr<BinaryReader> reader);
};

class SkeletonLimbFactoryV0 : public ResourceVersionFactory
{
  public:
    void ParseFileBinary(std::shared_ptr<BinaryReader> reader, std::shared_ptr<Resource> resource) override;
};
}; // namespace Ship
