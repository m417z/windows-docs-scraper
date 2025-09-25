typedef struct D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT {
  D3D11_1DDI_OMAC omac;
  GUID            QueryType;
  HANDLE          hChannel;
  UINT            SequenceNumber;
  HRESULT         ReturnCode;
} D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT;