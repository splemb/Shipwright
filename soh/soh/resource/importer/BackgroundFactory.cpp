#include "soh/resource/importer/BackgroundFactory.h"
#include "soh/resource/type/Background.h"
#include "spdlog/spdlog.h"

namespace Ship {
std::shared_ptr<Resource> BackgroundFactory::ReadResource(uint32_t version, std::shared_ptr<BinaryReader> reader) {
    auto resource = std::make_shared<Background>();
    std::shared_ptr<ResourceVersionFactory> factory = nullptr;

    switch (version) {
        case 0:
            factory = std::make_shared<BackgroundFactoryV0>();
            break;
    }

    if (factory == nullptr) {
        SPDLOG_ERROR("Failed to load Background with version {}", version);
        return nullptr;
    }

    factory->ParseFileBinary(reader, resource);

    return resource;
}

void BackgroundFactoryV0::ParseFileBinary(std::shared_ptr<BinaryReader> reader, std::shared_ptr<Resource> resource) {
    std::shared_ptr<Background> background = std::static_pointer_cast<Background>(resource);
    ResourceVersionFactory::ParseFileBinary(reader, background);

    uint32_t dataSize = reader->ReadUInt32();

    background->Data.reserve(dataSize);

    for (uint32_t i = 0; i < dataSize; i++) {
        background->Data.push_back(reader->ReadUByte());
    }
}
} // namespace Ship
