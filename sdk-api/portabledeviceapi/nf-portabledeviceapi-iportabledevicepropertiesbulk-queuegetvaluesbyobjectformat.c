HRESULT QueueGetValuesByObjectFormat(
  [in]  REFGUID                               pguidObjectFormat,
  [in]  LPCWSTR                               pszParentObjectID,
  [in]  const DWORD                           dwDepth,
  [in]  IPortableDeviceKeyCollection          *pKeys,
  [in]  IPortableDevicePropertiesBulkCallback *pCallback,
  [out] GUID                                  *pContext
);