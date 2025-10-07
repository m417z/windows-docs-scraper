NTSTATUS NCryptEncapsulate (
    [in]    NCRYPT_KEY_HANDLE hKey
    [out]   PBYTE             pbSecretKey,
    [in]    ULONG             cbSecretKey,
    [out]   ULONG             *pcbSecretKey,
    [out]   PBYTE             pbCipherText,
    [in]    ULONG             cbCipherText,
    [out]   ULONG             *pcbCipherText,
    [in]    ULONG             dwFlags
);