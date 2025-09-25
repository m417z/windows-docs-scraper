typedef struct _CRYPT_CREDENTIALS {
  DWORD  cbSize;
  LPCSTR pszCredentialsOid;
  LPVOID pvCredentials;
} CRYPT_CREDENTIALS, *PCRYPT_CREDENTIALS;