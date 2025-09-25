typedef struct _NDK_PD_DISPATCH {
  NDK_FN_CLOSE_OBJECT                       NdkClosePd;
  NDK_FN_QUERY_EXTENSION_INTERFACE          NdkQueryExtension;
  NDK_FN_CREATE_MR                          NdkCreateMr;
  NDK_FN_CREATE_MW                          NdkCreateMw;
  NDK_FN_CREATE_SRQ                         NdkCreateSrq;
  NDK_FN_CREATE_QP                          NdkCreateQp;
  NDK_FN_CREATE_QP_WITH_SRQ                 NdkCreateQpWithSrq;
  NDK_FN_GET_PRIVILEGED_MEMORY_REGION_TOKEN NdkGetPrivilegedMemoryRegionToken;
} NDK_PD_DISPATCH;