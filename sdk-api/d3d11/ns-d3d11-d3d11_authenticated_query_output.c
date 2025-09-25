typedef struct D3D11_AUTHENTICATED_QUERY_OUTPUT {
  D3D11_OMAC omac;
  GUID       QueryType;
  HANDLE     hChannel;
  UINT       SequenceNumber;
  HRESULT    ReturnCode;
} D3D11_AUTHENTICATED_QUERY_OUTPUT;