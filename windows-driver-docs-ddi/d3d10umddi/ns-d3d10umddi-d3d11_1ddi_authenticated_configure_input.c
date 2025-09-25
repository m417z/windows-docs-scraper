typedef struct D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT {
  D3D11_1DDI_OMAC omac;
  GUID            ConfigureType;
  HANDLE          hChannel;
  UINT            SequenceNumber;
} D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT;