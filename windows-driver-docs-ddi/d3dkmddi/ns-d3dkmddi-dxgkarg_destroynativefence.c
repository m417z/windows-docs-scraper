typedef struct _DXGKARG_DESTROYNATIVEFENCE {
  HANDLE                        hGlobalNativeFence;
  DXGK_DESTROYNATIVEFENCE_FLAGS Flags;
  BYTE                          Reserved[32];
} DXGKARG_DESTROYNATIVEFENCE;