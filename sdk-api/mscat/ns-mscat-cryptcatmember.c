typedef struct CRYPTCATMEMBER_ {
  DWORD                     cbStruct;
  LPWSTR                    pwszReferenceTag;
  LPWSTR                    pwszFileName;
  GUID                      gSubjectType;
  DWORD                     fdwMemberFlags;
  struct SIP_INDIRECT_DATA_ *pIndirectData;
  DWORD                     dwCertVersion;
  DWORD                     dwReserved;
  HANDLE                    hReserved;
  CRYPT_ATTR_BLOB           sEncodedIndirectData;
  CRYPT_ATTR_BLOB           sEncodedMemberInfo;
} CRYPTCATMEMBER;