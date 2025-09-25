HRESULT InitializeEncode(
  [in]           IX509PrivateKey *pKey,
  [in]           EncodingType    Encoding,
  [in]           BSTR            strCAXCert,
  [in, optional] IObjectId       *pAlgorithm,
  [in]           LONG            EncryptionStrength
);