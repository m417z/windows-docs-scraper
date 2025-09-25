typedef struct _DXGKARG_CLOSENATIVEFENCE {
  HANDLE                      hLocalNativeFence;
  DXGK_CLOSENATIVEFENCE_FLAGS Flags;
  BYTE                        Reserved[32];
} DXGKARG_CLOSENATIVEFENCE;