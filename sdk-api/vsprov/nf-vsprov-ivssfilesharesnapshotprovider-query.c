HRESULT Query(
  [in]  VSS_ID          QueriedObjectId,
  [in]  VSS_OBJECT_TYPE eQueriedObjectType,
  [in]  VSS_OBJECT_TYPE eReturnedObjectsType,
  [out] IVssEnumObject  **ppEnum
);