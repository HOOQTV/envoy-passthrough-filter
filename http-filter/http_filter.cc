#include <string>
#include <iostream>

#include "http_filter.h"

#include "server/config/network/http_connection_manager.h"

namespace Envoy {
namespace Http {

HttpSampleFilter::HttpSampleFilter() {}

HttpSampleFilter::~HttpSampleFilter() {}

void HttpSampleFilter::onDestroy() {}

const LowerCaseString& HttpSampleFilter::headerKey() {
  static LowerCaseString* key = new LowerCaseString("via");
  return *key;
}

const std::string& HttpSampleFilter::headerValue() {
  static std::string* val = new std::string("sample-filter");
  return *val;
}

FilterHeadersStatus HttpSampleFilter::decodeHeaders(HeaderMap&, bool) {
  return FilterHeadersStatus::Continue;
}

FilterDataStatus HttpSampleFilter::decodeData(Buffer::Instance&, bool) {
  return FilterDataStatus::Continue;
}

FilterTrailersStatus HttpSampleFilter::decodeTrailers(HeaderMap&) {
  return FilterTrailersStatus::Continue;
}

FilterHeadersStatus HttpSampleFilter::encodeHeaders(HeaderMap& headers, bool) {
  headers.addReference(headerKey(), headerValue());
  return FilterHeadersStatus::Continue;
}

FilterDataStatus HttpSampleFilter::encodeData(Buffer::Instance&, bool) {
  return FilterDataStatus::Continue;
}

FilterTrailersStatus HttpSampleFilter::encodeTrailers(HeaderMap&) {
  return FilterTrailersStatus::Continue;
}

void HttpSampleFilter::setDecoderFilterCallbacks(StreamDecoderFilterCallbacks& callbacks) {
  decoder_callbacks_ = &callbacks;
}

void HttpSampleFilter::setEncoderFilterCallbacks(StreamEncoderFilterCallbacks& callbacks) {
  encoder_callbacks_ = &callbacks;
}

} // Http
} // Envoy
