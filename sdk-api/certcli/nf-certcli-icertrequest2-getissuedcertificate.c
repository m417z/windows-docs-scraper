HRESULT GetIssuedCertificate(
  [in]          const BSTR strConfig,
  [in]          LONG       RequestId,
  [in]          const BSTR strSerialNumber,
  [out, retval] LONG       *pDisposition
);