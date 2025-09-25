BOOL FindActCtxSectionStringW(
  [in]  DWORD                      dwFlags,
  [in]  const GUID                 *lpExtensionGuid,
  [in]  ULONG                      ulSectionId,
  [in]  LPCWSTR                    lpStringToFind,
  [out] PACTCTX_SECTION_KEYED_DATA ReturnedData
);