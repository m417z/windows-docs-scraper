SECURITY_STATUS NCryptDecapsulate (
 [in]    NCRYPT_KEY_HANDLE hKey,
 [in]    PCBYTE            pbCipherText,
 [in]    ULONG             cbCipherText,
 [out]   PBYTE             pbSecretKey,
 [in]    ULONG             cbSecretKey,
 [out]   ULONG             *pcbSecretKey,
 [in]    ULONG             dwFlags
);