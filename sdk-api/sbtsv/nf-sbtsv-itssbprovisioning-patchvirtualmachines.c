HRESULT PatchVirtualMachines(
  [in]           BSTR                              JobXmlString,
  [in]           BSTR                              JobGuid,
  [in]           ITsSbProvisioningPluginNotifySink *pSink,
  [in, optional] VM_PATCH_INFO                     *pVMPatchInfo
);