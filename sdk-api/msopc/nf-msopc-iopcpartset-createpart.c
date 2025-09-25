HRESULT CreatePart(
  [in]          IOpcPartUri             *name,
  [in]          LPCWSTR                 contentType,
  [in]          OPC_COMPRESSION_OPTIONS compressionOptions,
  [out, retval] IOpcPart                **part
);