PFN_AUTHENTICODE_DIGEST_SIGN_EX pfnAuthenticodeDigestSignEx;

HRESULT __stdcall pfnAuthenticodeDigestSignEx(
    _In_opt_ PCRYPT_DATA_BLOB pMetadataBlob,         
    _In_ ALG_ID digestAlgId,                                 
    _In_ PBYTE pbToBeSignedDigest, 
    _In_ DWORD cbToBeSignedDigest,                           
    _Out_ PCRYPT_DATA_BLOB pSignedDigest,                    
    _Out_ PCCERT_CONTEXT* ppSignerCert,                      
    _Inout_ HCERTSTORE hCertChainStore                       
);