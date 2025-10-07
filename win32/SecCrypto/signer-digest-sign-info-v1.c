typedef struct SIGNER_DIGEST_SIGN_INFO_V1
    {
        DWORD cbSize;                                                //Required: should be set to sizeof(SIGNER_DIGEST_SIGN_INFO_V1)
        PFN_AUTHENTICODE_DIGEST_SIGN pfnAuthenticodeDigestSign;      //Required: pointer to AuthenticodeDigestSign function
        PCRYPT_DATA_BLOB pMetadataBlob;                              //Optional: metadata blob (opaque to SignerSignEx3)
    } SIGNER_DIGEST_SIGN_INFO_V1, *PSIGNER_DIGEST_SIGN_INFO_V1;