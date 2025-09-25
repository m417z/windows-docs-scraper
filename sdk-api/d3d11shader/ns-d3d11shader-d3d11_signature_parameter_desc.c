typedef struct _D3D11_SIGNATURE_PARAMETER_DESC {
  LPCSTR                      SemanticName;
  UINT                        SemanticIndex;
  UINT                        Register;
  D3D_NAME                    SystemValueType;
  D3D_REGISTER_COMPONENT_TYPE ComponentType;
  BYTE                        Mask;
  BYTE                        ReadWriteMask;
  UINT                        Stream;
  D3D_MIN_PRECISION           MinPrecision;
} D3D11_SIGNATURE_PARAMETER_DESC;