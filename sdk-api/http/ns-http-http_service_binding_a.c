typedef struct _HTTP_SERVICE_BINDING_A {
  HTTP_SERVICE_BINDING_BASE Base;
  PCHAR                     Buffer;
  ULONG                     BufferSize;
} HTTP_SERVICE_BINDING_A, *PHTTP_SERVICE_BINDING_A;