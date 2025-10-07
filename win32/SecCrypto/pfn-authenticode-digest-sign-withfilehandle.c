PFN_AUTHENTICODE_DIGEST_SIGN_WITHFILEHANDLE pfnAuthenticodeDigestSignWithFileHandle;

HRESULT __stdcall pfnAuthenticodeDigestSignWithFileHandle(
    _In_ PCCERT_CONTEXT pSigningCert,                        
    _In_opt_ PCRYPT_DATA_BLOB pMetadataBlob,                 
    _In_ ALG_ID digestAlgId,                                 
    _In_ PBYTE pbToBeSignedDigest, 
    _In_ DWORD cbToBeSignedDigest,    
    _In_ HANDLE hFile,                   
    _Out_ PCRYPT_DATA_BLOB pSignedDigest                     
);
                     
);