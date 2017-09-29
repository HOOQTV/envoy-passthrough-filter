## Passthrough filter

### Building

I use linux vm inside my mac. Hehe.

0. clonse this repo, `cd envoy-passthrough`
1. `git clone --depth 1 https://github.com/envoyproxy/envoy.git`
2. `bazel build //http-filter:envoy`
3. Create a config, e.g. https://github.com/envoyproxy/envoy/blob/master/configs/google_com_proxy.json
4. Run it. `bazel-bin/http-filter/envoy -c google_com_proxy.json`

Inspect the http-filter dir. You'll find how easy it is to build a filter with envoy!
