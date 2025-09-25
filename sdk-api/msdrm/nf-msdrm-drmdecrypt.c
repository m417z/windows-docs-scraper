DRMEXPORT HRESULT UDAPICALL DRMDecrypt(
  [in]      DRMHANDLE hCryptoProvider,
  [in]      UINT      iPosition,
  [in]      UINT      cNumInBytes,
  [in]      BYTE      *pbInData,
  [in, out] UINT      *pcNumOutBytes,
  [out]     BYTE      *pbOutData
);