BOOL CryptSIPGetSignedDataMsg(
  [in]      SIP_SUBJECTINFO *pSubjectInfo,
  [out]     DWORD           *pdwEncodingType,
  [in]      DWORD           dwIndex,
  [in, out] DWORD           *pcbSignedDataMsg,
  [out]     BYTE            *pbSignedDataMsg
);