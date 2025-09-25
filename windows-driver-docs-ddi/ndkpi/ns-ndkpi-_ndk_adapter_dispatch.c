typedef struct _NDK_ADAPTER_DISPATCH {
  NDK_FN_QUERY_EXTENSION_INTERFACE NdkQueryExtension;
  NDK_FN_QUERY_ADAPTER_INFO        NdkQueryAdapterInfo;
  NDK_FN_CREATE_CQ                 NdkCreateCq;
  NDK_FN_CREATE_PD                 NdkCreatePd;
  NDK_FN_CREATE_SHARED_ENDPOINT    NdkCreateSharedEndpoint;
  NDK_FN_CREATE_CONNECTOR          NdkCreateConnector;
  NDK_FN_CREATE_LISTENER           NdkCreateListener;
  NDK_FN_BUILD_LAM                 NdkBuildLAM;
  NDK_FN_RELEASE_LAM               NdkReleaseLAM;
} NDK_ADAPTER_DISPATCH;