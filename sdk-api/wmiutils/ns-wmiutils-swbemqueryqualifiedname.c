typedef struct tag_SWbemQueryQualifiedName {
  ULONG   m_uVersion;
  ULONG   m_uTokenType;
  ULONG   m_uNameListSize;
  LPCWSTR *m_ppszNameList;
  BOOL    m_bArraysUsed;
  BOOL    *m_pbArrayElUsed;
  ULONG   *m_puArrayIndex;
} SWbemQueryQualifiedName;