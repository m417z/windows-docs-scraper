typedef struct D3D12_ROOT_PARAMETER1 {
  D3D12_ROOT_PARAMETER_TYPE ParameterType;
  union {
    D3D12_ROOT_DESCRIPTOR_TABLE1 DescriptorTable;
    D3D12_ROOT_CONSTANTS         Constants;
    D3D12_ROOT_DESCRIPTOR1       Descriptor;
  };
  D3D12_SHADER_VISIBILITY   ShaderVisibility;
} D3D12_ROOT_PARAMETER1;