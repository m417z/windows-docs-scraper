HRESULT ConvertVersion(
  [in]      ISyncKnowledge     *pKnowledgeIn,
  [in]      const BYTE         *pbCurrentOwnerId,
  [in]      const SYNC_VERSION *pVersionIn,
  [in]      BYTE               *pbNewOwnerId,
  [in, out] DWORD              *pcbIdSize,
  [out]     SYNC_VERSION       *pVersionOut
);