typedef struct _HTTP_SERVICE_BINDING_W {
  HTTP_SERVICE_BINDING_BASE Base;
  PWCHAR                    Buffer;
  ULONG                     BufferSize;
} HTTP_SERVICE_BINDING_W, *PHTTP_SERVICE_BINDING_W;