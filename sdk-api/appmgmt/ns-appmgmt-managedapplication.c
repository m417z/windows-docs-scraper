typedef struct _MANAGEDAPPLICATION {
  LPWSTR pszPackageName;
  LPWSTR pszPublisher;
  DWORD  dwVersionHi;
  DWORD  dwVersionLo;
  DWORD  dwRevision;
  GUID   GpoId;
  LPWSTR pszPolicyName;
  GUID   ProductId;
  LANGID Language;
  LPWSTR pszOwner;
  LPWSTR pszCompany;
  LPWSTR pszComments;
  LPWSTR pszContact;
  LPWSTR pszSupportUrl;
  DWORD  dwPathType;
  BOOL   bInstalled;
} MANAGEDAPPLICATION, *PMANAGEDAPPLICATION;