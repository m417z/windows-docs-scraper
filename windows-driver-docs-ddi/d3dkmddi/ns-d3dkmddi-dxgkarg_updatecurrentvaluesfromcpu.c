typedef struct _DXGKARG_UPDATECURRENTVALUESFROMCPU {
  HANDLE                                *NativeFenceArray;
  UINT64                                *UpdatedValueArray;
  void                                  **CurrentValueKernelCpuVa;
  UINT                                  NumFences;
  DXGK_UPDATECURRENTVALUESFROMCPU_FLAGS Flags;
  BYTE                                  Reserved[28];
} DXGKARG_UPDATECURRENTVALUESFROMCPU;