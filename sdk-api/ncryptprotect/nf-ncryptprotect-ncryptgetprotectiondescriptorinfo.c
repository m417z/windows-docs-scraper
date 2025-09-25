SECURITY_STATUS NCryptGetProtectionDescriptorInfo(
  [in]           NCRYPT_DESCRIPTOR_HANDLE hDescriptor,
  [in, optional] const NCRYPT_ALLOC_PARA  *pMemPara,
                 DWORD                    dwInfoType,
  [out]          void                     **ppvInfo
);