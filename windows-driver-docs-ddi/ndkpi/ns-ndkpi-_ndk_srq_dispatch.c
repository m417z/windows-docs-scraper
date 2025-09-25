typedef struct _NDK_SRQ_DISPATCH {
  NDK_FN_CLOSE_OBJECT              NdkCloseSrq;
  NDK_FN_QUERY_EXTENSION_INTERFACE NdkQueryExtension;
  NDK_FN_MODIFY_SRQ                NdkModifySrq;
  NDK_FN_SRQ_RECEIVE               NdkSrqReceive;
} NDK_SRQ_DISPATCH;