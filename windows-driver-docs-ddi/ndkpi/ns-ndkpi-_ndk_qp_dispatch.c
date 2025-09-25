typedef struct _NDK_QP_DISPATCH {
  NDK_FN_CLOSE_OBJECT              NdkCloseQp;
  NDK_FN_QUERY_EXTENSION_INTERFACE NdkQueryExtension;
  NDK_FN_FLUSH                     NdkFlush;
  NDK_FN_SEND                      NdkSend;
  NDK_FN_RECEIVE                   NdkReceive;
  NDK_FN_BIND                      NdkBind;
  NDK_FN_FAST_REGISTER             NdkFastRegister;
  NDK_FN_INVALIDATE                NdkInvalidate;
  NDK_FN_READ                      NdkRead;
  NDK_FN_WRITE                     NdkWrite;
  NDK_FN_SEND_AND_INVALIDATE       NdkSendAndInvalidate;
} NDK_QP_DISPATCH;