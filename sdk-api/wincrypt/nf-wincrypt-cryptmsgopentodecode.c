HCRYPTMSG CryptMsgOpenToDecode(
  [in]           DWORD             dwMsgEncodingType,
  [in]           DWORD             dwFlags,
  [in]           DWORD             dwMsgType,
  [in]           HCRYPTPROV_LEGACY hCryptProv,
  [in]           PCERT_INFO        pRecipientInfo,
  [in, optional] PCMSG_STREAM_INFO pStreamInfo
);