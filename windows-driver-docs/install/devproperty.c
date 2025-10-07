typedef struct _DEVPROPERTY {
  DEVPROPCOMPKEY CompKey;
  DEVPROPTYPE    Type;
  ULONG          BufferSize;
  PVOID          Buffer;
} DEVPROPERTY, *PDEVPROPERTY;