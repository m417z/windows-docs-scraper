HRESULT OnVirtualMachineStatusChanged(
  [in] VM_NOTIFY_ENTRY  *pVmNotifyEntry,
  [in] VM_NOTIFY_STATUS VmNotifyStatus,
  [in] HRESULT          ErrorCode,
  [in] BSTR             ErrorDescr
);