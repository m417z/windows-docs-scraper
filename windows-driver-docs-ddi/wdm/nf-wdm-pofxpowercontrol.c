NTSTATUS PoFxPowerControl(
  [in]            POHANDLE Handle,
  [in]            LPCGUID  PowerControlCode,
  [in, optional]  PVOID    InBuffer,
  [in]            SIZE_T   InBufferSize,
  [out, optional] PVOID    OutBuffer,
  [in]            SIZE_T   OutBufferSize,
  [out, optional] PSIZE_T  BytesReturned
);