struct DML_BINDING_TABLE_DESC {
  IDMLDispatchable            *Dispatchable;
  D3D12_CPU_DESCRIPTOR_HANDLE CPUDescriptorHandle;
  D3D12_GPU_DESCRIPTOR_HANDLE GPUDescriptorHandle;
  UINT                        SizeInDescriptors;
};