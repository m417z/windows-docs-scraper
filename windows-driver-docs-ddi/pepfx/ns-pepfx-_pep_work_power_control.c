typedef struct _PEP_WORK_POWER_CONTROL {
       POHANDLE DeviceHandle;
  [in] LPCGUID  PowerControlCode;
       PVOID    RequestContext;
  [in] PVOID    InBuffer;
  [in] SIZE_T   InBufferSize;
  [in] PVOID    OutBuffer;
  [in] SIZE_T   OutBufferSize;
} PEP_WORK_POWER_CONTROL, *PPEP_WORK_POWER_CONTROL;