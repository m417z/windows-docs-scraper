typedef struct D3D12_DEVICE_REMOVED_EXTENDED_DATA3 {
  HRESULT                             DeviceRemovedReason;
  D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1 AutoBreadcrumbsOutput;
  D3D12_DRED_PAGE_FAULT_OUTPUT2       PageFaultOutput;
  D3D12_DRED_DEVICE_STATE             DeviceState;
} D3D12_DEVICE_REMOVED_EXTENDED_DATA3;