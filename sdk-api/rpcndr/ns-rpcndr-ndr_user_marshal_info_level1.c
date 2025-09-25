typedef struct _NDR_USER_MARSHAL_INFO_LEVEL1 {
  void                     *Buffer;
  unsigned long            BufferSize;
  void * )(size_t)                     *(pfnAllocate;
  void()(void *)                    * pfnFree;
  struct IRpcChannelBuffer *pRpcChannelBuffer;
  ULONG_PTR                Reserved[5];
} NDR_USER_MARSHAL_INFO_LEVEL1;