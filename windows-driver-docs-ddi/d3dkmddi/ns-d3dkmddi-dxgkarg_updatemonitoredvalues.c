typedef struct _DXGKARG_UPDATEMONITOREDVALUES {
  HANDLE                              *NativeFenceArray;
  UINT64                              *UpdatedValueArray;
  void                                **MonitoredValueKernelCpuVa;
  UINT                                NumFences;
  DXGKARG_UPDATEMONITOREDVALUES_FLAGS Flags;
  BYTE                                Reserved[28];
} DXGKARG_UPDATEMONITOREDVALUES;