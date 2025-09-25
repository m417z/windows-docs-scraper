FILEHC_EXPORT BOOL AssociateContextWithName(
  [in] PNAME_CACHE_CONTEXT  pNameCache,
  [in] LPBYTE               lpbName,
  [in] DWORD                cbName,
  [in] LPBYTE               lpbData,
  [in] DWORD                cbData,
  [in] PGENERIC_MAPPING     pGenericMapping,
  [in] PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in] FIO_CONTEXT          *pContext,
  [in] BOOL                 fKeepReference
);