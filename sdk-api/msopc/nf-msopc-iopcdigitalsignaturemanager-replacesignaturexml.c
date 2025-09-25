HRESULT ReplaceSignatureXml(
  [in]          IOpcPartUri          *signaturePartName,
  [in]          const UINT8          *newSignatureXml,
  [in]          UINT32               count,
  [out, retval] IOpcDigitalSignature **digitalSignature
);