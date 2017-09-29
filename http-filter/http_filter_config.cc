#include <string>

#include "http_filter.h"

#include "envoy/registry/registry.h"

namespace Envoy {
namespace Server {
namespace Configuration {

class HttpSampleFilterConfig : public NamedHttpFilterConfigFactory {
public:
  HttpFilterFactoryCb createFilterFactory(const Json::Object&, const std::string&,
                                          FactoryContext&) override {
    return [](Http::FilterChainFactoryCallbacks& callbacks) -> void {
      callbacks.addStreamFilter(
          Http::StreamFilterSharedPtr{new Http::HttpSampleFilter()});
    };
  }
  std::string name() override { return "pass"; }
};

/**
 * Static registration for this sample filter. @see RegisterFactory.
 */
static Registry::RegisterFactory<HttpSampleFilterConfig, NamedHttpFilterConfigFactory>
    register_;

} // Configuration
} // Server
} // Envoy
