HCRYPTMSG CryptMsgOpenToEncode(
  [in]           DWORD             dwMsgEncodingType,
  [in]           DWORD             dwFlags,
  [in]           DWORD             dwMsgType,
  [in]           void const        *pvMsgEncodeInfo,
  [in, optional] LPSTR             pszInnerContentObjID,
  [in]           PCMSG_STREAM_INFO pStreamInfo
);