HRESULT ResolveResource(
  [out] DWORD         *resourceType,
  [out] wchar_t [256] resourceLocation,
  [out] wchar_t [256] endPointName,
  [in]  wchar_t       *userID,
  [in]  wchar_t       *alias
);