HRESULT DeleteSnapshots(
  [in]  VSS_ID          SourceObjectId,
  [in]  VSS_OBJECT_TYPE eSourceObjectType,
  [in]  BOOL            bForceDelete,
  [out] LONG            *plDeletedSnapshots,
  [out] VSS_ID          *pNondeletedSnapshotID
);