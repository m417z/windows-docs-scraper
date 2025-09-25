HRESULT UnpackFontFile(
        DWRITE_CONTAINER_TYPE containerType,
  [in]  void const            *fileData,
        UINT32                fileDataSize,
  [out] IDWriteFontFileStream **unpackedFontStream
);