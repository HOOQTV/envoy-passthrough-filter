#pragma once

#include <string>

#include "server/config/network/http_connection_manager.h"

namespace Envoy {
namespace Http {

class HttpSampleFilter : public StreamFilter {
public:
  HttpSampleFilter();
  ~HttpSampleFilter();

  // Http::StreamFilterBase
  void onDestroy() override;

  FilterHeadersStatus encodeHeaders(HeaderMap& headers, bool) override;
  FilterDataStatus encodeData(Buffer::Instance&, bool) override;
  FilterTrailersStatus encodeTrailers(HeaderMap&) override;

  FilterHeadersStatus decodeHeaders(HeaderMap& headers, bool) override;
  FilterDataStatus decodeData(Buffer::Instance&, bool) override;
  FilterTrailersStatus decodeTrailers(HeaderMap&) override;

  void setDecoderFilterCallbacks(StreamDecoderFilterCallbacks& callbacks) override;
  void setEncoderFilterCallbacks(StreamEncoderFilterCallbacks& callbacks) override;

private:
  StreamDecoderFilterCallbacks* decoder_callbacks_{nullptr};
  StreamEncoderFilterCallbacks* encoder_callbacks_{nullptr};

  // Http::HeaderMap* response_headers_{nullptr};

  const LowerCaseString& headerKey();
  const std::string& headerValue();
};

} // Http
} // Envoy
