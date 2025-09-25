typedef struct _NDK_MR_DISPATCH {
  NDK_FN_CLOSE_OBJECT                NdkCloseMr;
  NDK_FN_QUERY_EXTENSION_INTERFACE   NdkQueryExtension;
  NDK_FN_REGISTER_MR                 NdkRegisterMr;
  NDK_FN_DEREGISTER_MR               NdkDeregisterMr;
  NDK_FN_INITIALIZE_FAST_REGISTER_MR NdkInitializeFastRegisterMr;
  NDK_FN_GET_REMOTE_TOKEN_FROM_MR    NdkGetRemoteTokenFromMr;
  NDK_FN_GET_LOCAL_TOKEN_FROM_MR     NdkGetLocalTokenFromMr;
} NDK_MR_DISPATCH;