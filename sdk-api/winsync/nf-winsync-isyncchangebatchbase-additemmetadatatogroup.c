HRESULT AddItemMetadataToGroup(
  [in]      const BYTE         *pbOwnerReplicaId,
  [in]      const BYTE         *pbItemId,
  [in]      const SYNC_VERSION *pChangeVersion,
  [in]      const SYNC_VERSION *pCreationVersion,
  [in]      DWORD              dwFlags,
  [in]      DWORD              dwWorkForChange,
  [in, out] ISyncChangeBuilder **ppChangeBuilder
);