typedef struct _PEP_POWER_CONTROL_COMPLETE {
  [in] PEPHANDLE DeviceHandle;
  [in] LPCGUID   PowerControlCode;
  [in] PVOID     RequestContext;
  [in] SIZE_T    BytesReturned;
  [in] NTSTATUS  Status;
} PEP_POWER_CONTROL_COMPLETE, *PPEP_POWER_CONTROL_COMPLETE;