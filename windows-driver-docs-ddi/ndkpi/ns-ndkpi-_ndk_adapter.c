typedef struct _NDK_ADAPTER {
  NDK_OBJECT_HEADER          Header;
  const NDK_ADAPTER_DISPATCH *Dispatch;
} NDK_ADAPTER;