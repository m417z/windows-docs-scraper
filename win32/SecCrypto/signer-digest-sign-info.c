typedef struct _SIGNER_DIGEST_SIGN_INFO
{
    DWORD cbSize;                                                
    DWORD dwDigestSignChoice;                                    
    union
    {
		PFN_AUTHENTICODE_DIGEST_SIGN pfnAuthenticodeDigestSign;                                   
        	PFN_AUTHENTICODE_DIGEST_SIGN_WITHFILEHANDLE pfnAuthenticodeDigestSignWithFileHandle;      
        PFN_AUTHENTICODE_DIGEST_SIGN_EX pfnAuthenticodeDigestSignEx;                              
        PFN_AUTHENTICODE_DIGEST_SIGN_EX_WITHFILEHANDLE pfnAuthenticodeDigestSignExWithFileHandle; 
    };
    PCRYPT_DATA_BLOB pMetadataBlob;                              
    DWORD dwReserved;                                            
    DWORD dwReserved2;
    DWORD dwReserved3;
}SIGNER_DIGEST_SIGN_INFO, *PSIGNER_DIGEST_SIGN_INFO;