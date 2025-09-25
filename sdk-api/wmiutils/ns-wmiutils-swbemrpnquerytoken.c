typedef struct tag_SWbemRpnQueryToken {
  ULONG                   m_uVersion;
  ULONG                   m_uTokenType;
  ULONG                   m_uSubexpressionShape;
  ULONG                   m_uOperator;
  SWbemQueryQualifiedName *m_pRightIdent;
  SWbemQueryQualifiedName *m_pLeftIdent;
  ULONG                   m_uConstApparentType;
  SWbemRpnConst           m_Const;
  ULONG                   m_uConst2ApparentType;
  SWbemRpnConst           m_Const2;
  LPCWSTR                 m_pszRightFunc;
  LPCWSTR                 m_pszLeftFunc;
} SWbemRpnQueryToken;