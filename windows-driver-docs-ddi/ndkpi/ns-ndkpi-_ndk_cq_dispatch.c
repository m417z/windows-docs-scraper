typedef struct _NDK_CQ_DISPATCH {
  NDK_FN_CLOSE_OBJECT                    NdkCloseCq;
  NDK_FN_QUERY_EXTENSION_INTERFACE       NdkQueryExtension;
  NDK_FN_RESIZE_CQ                       NdkResizeCq;
  NDK_FN_ARM_CQ                          NdkArmCq;
  NDK_FN_GET_CQ_RESULTS                  NdkGetCqResults;
  NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION NdkControlCqInterruptModeration;
  NDK_FN_GET_CQ_RESULTS_EX               NdkGetCqResultsEx;
} NDK_CQ_DISPATCH;