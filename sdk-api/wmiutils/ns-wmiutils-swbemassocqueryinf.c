typedef struct tag_SWbemAssocQueryInf {
  ULONG     m_uVersion;
  ULONG     m_uAnalysisType;
  ULONG     m_uFeatureMask;
  IWbemPath *m_pPath;
  LPWSTR    m_pszPath;
  LPWSTR    m_pszQueryText;
  LPWSTR    m_pszResultClass;
  LPWSTR    m_pszAssocClass;
  LPWSTR    m_pszRole;
  LPWSTR    m_pszResultRole;
  LPWSTR    m_pszRequiredQualifier;
  LPWSTR    m_pszRequiredAssocQualifier;
} SWbemAssocQueryInf;