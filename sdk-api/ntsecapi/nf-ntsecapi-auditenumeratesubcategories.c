BOOLEAN AuditEnumerateSubCategories(
  [in]  const GUID *pAuditCategoryGuid,
  [in]  BOOLEAN    bRetrieveAllSubCategories,
  [out] GUID       **ppAuditSubCategoriesArray,
  [out] PULONG     pdwCountReturned
);