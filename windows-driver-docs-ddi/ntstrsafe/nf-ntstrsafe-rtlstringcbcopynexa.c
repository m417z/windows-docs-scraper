NTSTRSAFEDDI RtlStringCbCopyNExA(
  [out, optional] NTSTRSAFE_PSTR pszDest,
  [in]            size_t         cbDest,
  [in, optional]  STRSAFE_PCNZCH pszSrc,
                  size_t         cbToCopy,
  [out, optional] NTSTRSAFE_PSTR *ppszDestEnd,
  [out, optional] size_t         *pcbRemaining,
  [in]            DWORD          dwFlags
);