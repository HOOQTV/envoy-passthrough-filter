package(default_visibility = ["//visibility:public"])

load(
    "@envoy//bazel:envoy_build_system.bzl",
    "envoy_cc_binary"
)

envoy_cc_binary(
    name = "envoy",
    repository = "@envoy",
    deps = [
        ":echo2_config",
        "@envoy//source/exe:envoy_main_entry_lib",
    ],
)

