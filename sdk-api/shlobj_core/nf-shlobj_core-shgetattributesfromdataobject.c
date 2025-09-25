HRESULT SHGetAttributesFromDataObject(
  [in, optional]  IDataObject *pdo,
                  DWORD       dwAttributeMask,
  [out, optional] DWORD       *pdwAttributes,
  [out, optional] UINT        *pcItems
);