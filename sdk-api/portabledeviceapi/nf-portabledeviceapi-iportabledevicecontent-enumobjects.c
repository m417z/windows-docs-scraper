HRESULT EnumObjects(
  [in]  const DWORD                  dwFlags,
  [in]  LPCWSTR                      pszParentObjectID,
  [in]  IPortableDeviceValues        *pFilter,
  [out] IEnumPortableDeviceObjectIDs **ppEnum
);