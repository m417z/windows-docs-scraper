typedef struct _BCryptBuffer {
  ULONG cbBuffer;
  ULONG BufferType;
  PVOID pvBuffer;
} BCryptBuffer, *PBCryptBuffer;