NTDSAPI DWORD DsMapSchemaGuidsW(
  [in]  HANDLE              hDs,
  [in]  DWORD               cGuids,
  [in]  GUID                *rGuids,
  [out] DS_SCHEMA_GUID_MAPW **ppGuidMap
);