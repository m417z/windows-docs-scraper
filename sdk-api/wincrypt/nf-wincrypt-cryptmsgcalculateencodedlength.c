DWORD CryptMsgCalculateEncodedLength(
  [in]           DWORD      dwMsgEncodingType,
  [in]           DWORD      dwFlags,
  [in]           DWORD      dwMsgType,
  [in]           void const *pvMsgEncodeInfo,
  [in, optional] LPSTR      pszInnerContentObjID,
  [in]           DWORD      cbData
);