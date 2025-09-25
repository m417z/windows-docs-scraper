typedef struct _NDK_LISTENER {
  NDK_OBJECT_HEADER           Header;
  const NDK_LISTENER_DISPATCH *Dispatch;
} NDK_LISTENER;