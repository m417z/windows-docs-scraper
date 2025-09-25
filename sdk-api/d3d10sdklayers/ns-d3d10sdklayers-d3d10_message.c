typedef struct D3D10_MESSAGE {
  D3D10_MESSAGE_CATEGORY Category;
  D3D10_MESSAGE_SEVERITY Severity;
  D3D10_MESSAGE_ID       ID;
  const char             *pDescription;
  SIZE_T                 DescriptionByteLength;
} D3D10_MESSAGE;