BOOL FindActCtxSectionGuid(
  [in]  DWORD                      dwFlags,
  [in]  const GUID                 *lpExtensionGuid,
  [in]  ULONG                      ulSectionId,
  [in]  const GUID                 *lpGuidToFind,
  [out] PACTCTX_SECTION_KEYED_DATA ReturnedData
);