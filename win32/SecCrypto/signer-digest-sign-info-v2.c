typedef struct SIGNER_DIGEST_SIGN_INFO_V2
    {
        DWORD cbSize;                                                
        PFN_AUTHENTICODE_DIGEST_SIGN pfnAuthenticodeDigestSign;      
        PFN_AUTHENTICODE_DIGEST_SIGN_EX pfnAuthenticodeDigestSignEx; 
        PCRYPT_DATA_BLOB pMetadataBlob;                              
    } SIGNER_DIGEST_SIGN_INFO_V2, *PSIGNER_DIGEST_SIGN_INFO_V2;