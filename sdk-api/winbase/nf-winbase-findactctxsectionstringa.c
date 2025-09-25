BOOL FindActCtxSectionStringA(
  [in]  DWORD                      dwFlags,
  [in]  const GUID                 *lpExtensionGuid,
  [in]  ULONG                      ulSectionId,
  [in]  LPCSTR                     lpStringToFind,
  [out] PACTCTX_SECTION_KEYED_DATA ReturnedData
);