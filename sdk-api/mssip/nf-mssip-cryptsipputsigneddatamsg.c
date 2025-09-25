BOOL CryptSIPPutSignedDataMsg(
  [in]  SIP_SUBJECTINFO *pSubjectInfo,
  [in]  DWORD           dwEncodingType,
  [out] DWORD           *pdwIndex,
  [in]  DWORD           cbSignedDataMsg,
  [in]  BYTE            *pbSignedDataMsg
);