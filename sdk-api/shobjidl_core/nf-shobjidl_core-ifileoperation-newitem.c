HRESULT NewItem(
  [in] IShellItem                 *psiDestinationFolder,
  [in] DWORD                      dwFileAttributes,
  [in] LPCWSTR                    pszName,
  [in] LPCWSTR                    pszTemplateName,
  [in] IFileOperationProgressSink *pfopsItem
);