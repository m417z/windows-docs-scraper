HRESULT OnVirtualMachineHostStatusChanged(
  [in] BSTR                  VmHost,
  [in] VM_HOST_NOTIFY_STATUS VmHostNotifyStatus,
  [in] HRESULT               ErrorCode,
  [in] BSTR                  ErrorDescr
);