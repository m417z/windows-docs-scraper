typedef enum _NVME_NAMESPACE_CONTROL_TYPE {
  NvmeQuerySupportedNamespaceControlTypes,
  NvmeNamespaceStart,
  NvmeNamespacePower,
  NvmeNamespacePoFxPowerInfo,
  NvmeNamespacePoFxPowerRequired,
  NvmeNamespacePoFxPowerActive,
  NvmeNamespacePoFxPowerSetFState,
  NvmeNamespacePoFxPowerControl,
  NvmeNamespaceRemove,
  NvmeNamespaceSurpriseRemoval,
  NvmeNamespaceControlMax,
  MakeNamespaceControlTypeSizeOfUlong
} NVME_NAMESPACE_CONTROL_TYPE, *PNVME_NAMESPACE_CONTROL_TYPE;