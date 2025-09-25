typedef struct _CRYPT_DECRYPT_MESSAGE_PARA {
  DWORD      cbSize;
  DWORD      dwMsgAndCertEncodingType;
  DWORD      cCertStore;
  HCERTSTORE *rghCertStore;
  DWORD      dwFlags;
} CRYPT_DECRYPT_MESSAGE_PARA, *PCRYPT_DECRYPT_MESSAGE_PARA;