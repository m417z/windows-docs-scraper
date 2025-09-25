typedef struct _NDK_SHARED_ENDPOINT {
  NDK_OBJECT_HEADER                  Header;
  const NDK_SHARED_ENDPOINT_DISPATCH *Dispatch;
} NDK_SHARED_ENDPOINT;