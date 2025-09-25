NTSTATUS SendPowerControl(
  [in]            PDEVICE_OBJECT _DeviceObject,
  [in]            LPCGUID        _PowerControlCode,
  [in, optional]  PVOID          _InBuffer,
  [in]            SIZE_T         _InBufferSize,
  [out, optional] PVOID          _OutBuffer,
  [in]            SIZE_T         _OutBufferSize,
  [out, optional] PSIZE_T        _BytesReturned
);