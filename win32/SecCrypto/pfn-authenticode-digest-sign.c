PFN_AUTHENTICODE_DIGEST_SIGN pfnAuthenticodeDigestSign; 

HRESULT __stdcall pfnAuthenticodeDigestSign(
    _In_ PCCERT_CONTEXT pSigningCert,                        
    _In_opt_ PCRYPT_DATA_BLOB pMetadataBlob,                 
    _In_ ALG_ID digestAlgId,                                 
    _In_ PBYTE pbToBeSignedDigest, 
    _In_ DWORD cbToBeSignedDigest,                           
    _Out_ PCRYPT_DATA_BLOB pSignedDigest                     
);