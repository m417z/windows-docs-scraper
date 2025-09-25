typedef struct _SCHANNEL_CERT_HASH {
  DWORD      dwLength;
  DWORD      dwFlags;
  HCRYPTPROV hProv;
  BYTE       ShaHash[20];
} SCHANNEL_CERT_HASH, *PSCHANNEL_CERT_HASH;