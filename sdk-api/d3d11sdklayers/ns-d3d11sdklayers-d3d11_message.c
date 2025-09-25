typedef struct D3D11_MESSAGE {
  D3D11_MESSAGE_CATEGORY Category;
  D3D11_MESSAGE_SEVERITY Severity;
  D3D11_MESSAGE_ID       ID;
  const char             *pDescription;
  SIZE_T                 DescriptionByteLength;
} D3D11_MESSAGE;