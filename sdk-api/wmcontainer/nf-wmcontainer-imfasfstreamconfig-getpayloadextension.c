HRESULT GetPayloadExtension(
  [in]      WORD  wPayloadExtensionNumber,
  [out]     GUID  *pguidExtensionSystemID,
  [out]     WORD  *pcbExtensionDataSize,
  [out]     BYTE  *pbExtensionSystemInfo,
  [in, out] DWORD *pcbExtensionSystemInfo
);