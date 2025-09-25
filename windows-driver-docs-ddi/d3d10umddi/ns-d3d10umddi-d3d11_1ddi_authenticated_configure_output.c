typedef struct D3D11_1DDI_AUTHENTICATED_CONFIGURE_OUTPUT {
  D3D11_1DDI_OMAC omac;
  GUID            ConfigureType;
  HANDLE          hChannel;
  UINT            SequenceNumber;
  HRESULT         ReturnCode;
} D3D11_1DDI_AUTHENTICATED_CONFIGURE_OUTPUT;