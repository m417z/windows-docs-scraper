BOOL CryptMsgCountersign(
  [in, out] HCRYPTMSG                hCryptMsg,
  [in]      DWORD                    dwIndex,
  [in]      DWORD                    cCountersigners,
  [in]      PCMSG_SIGNER_ENCODE_INFO rgCountersigners
);