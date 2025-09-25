NTSTRSAFEDDI RtlStringCchCopyNExW(
  [out, optional] NTSTRSAFE_PWSTR pszDest,
  [in]            size_t          cchDest,
  [in, optional]  STRSAFE_PCNZWCH pszSrc,
                  size_t          cchToCopy,
  [out, optional] NTSTRSAFE_PWSTR *ppszDestEnd,
  [out, optional] size_t          *pcchRemaining,
  [in]            DWORD           dwFlags
);