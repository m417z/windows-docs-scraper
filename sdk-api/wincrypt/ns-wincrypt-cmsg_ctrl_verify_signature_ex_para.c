typedef struct _CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA {
  DWORD             cbSize;
  HCRYPTPROV_LEGACY hCryptProv;
  DWORD             dwSignerIndex;
  DWORD             dwSignerType;
  void              *pvSigner;
} CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA, *PCMSG_CTRL_VERIFY_SIGNATURE_EX_PARA;