typedef struct _NDK_CONNECTOR {
  NDK_OBJECT_HEADER            Header;
  const NDK_CONNECTOR_DISPATCH *Dispatch;
} NDK_CONNECTOR;