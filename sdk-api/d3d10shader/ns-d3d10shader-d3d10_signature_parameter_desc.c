typedef struct _D3D10_SIGNATURE_PARAMETER_DESC {
  LPCSTR                        SemanticName;
  UINT                          SemanticIndex;
  UINT                          Register;
  D3D10_NAME                    SystemValueType;
  D3D10_REGISTER_COMPONENT_TYPE ComponentType;
  BYTE                          Mask;
  BYTE                          ReadWriteMask;
} D3D10_SIGNATURE_PARAMETER_DESC;