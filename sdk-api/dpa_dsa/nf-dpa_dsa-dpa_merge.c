BOOL DPA_Merge(
  [in, out] HDPA         hdpaDest,
  [in]      HDPA         hdpaSrc,
  [in]      DWORD        dwFlags,
  [in]      PFNDACOMPARE pfnCompare,
  [in]      PFNDPAMERGE  pfnMerge,
  [in]      LPARAM       lParam
);