typedef struct _PEP_POWER_CONTROL_REQUEST {
  [in]  PEPHANDLE DeviceHandle;
  [in]  LPCGUID   PowerControlCode;
  [in]  PVOID     InBuffer;
  [in]  SIZE_T    InBufferSize;
  [in]  PVOID     OutBuffer;
  [in]  SIZE_T    OutBufferSize;
  [out] SIZE_T    BytesReturned;
  [out] NTSTATUS  Status;
} PEP_POWER_CONTROL_REQUEST, *PPEP_POWER_CONTROL_REQUEST;