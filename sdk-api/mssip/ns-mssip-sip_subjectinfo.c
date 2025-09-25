typedef struct SIP_SUBJECTINFO_ {
  DWORD                      cbSize;
  GUID                       *pgSubjectType;
  HANDLE                     hFile;
  LPCWSTR                    pwsFileName;
  LPCWSTR                    pwsDisplayName;
  DWORD                      dwReserved1;
  DWORD                      dwIntVersion;
  HCRYPTPROV                 hProv;
  CRYPT_ALGORITHM_IDENTIFIER DigestAlgorithm;
  DWORD                      dwFlags;
  DWORD                      dwEncodingType;
  DWORD                      dwReserved2;
  DWORD                      fdwCAPISettings;
  DWORD                      fdwSecuritySettings;
  DWORD                      dwIndex;
  DWORD                      dwUnionChoice;
  union {
#if ...
    MS_ADDINFO_FLAT_                 *psFlat;
#else
    struct MS_ADDINFO_FLAT_          *psFlat;
#endif
#if ...
    MS_ADDINFO_CATALOGMEMBER_        *psCatMember;
#else
    struct MS_ADDINFO_CATALOGMEMBER_ *psCatMember;
#endif
#if ...
    MS_ADDINFO_BLOB_                 *psBlob;
#else
    struct MS_ADDINFO_BLOB_          *psBlob;
#endif
#if ...
    MS_ADDINFO_DETACHEDSIG_          *psDetachedSig;
#else
    struct MS_ADDINFO_DETACHEDSIG_   *psDetachedSig;
#endif
  };
  LPVOID                     pClientData;
} SIP_SUBJECTINFO, *LPSIP_SUBJECTINFO;