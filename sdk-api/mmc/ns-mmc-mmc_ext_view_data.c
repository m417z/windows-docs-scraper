typedef struct _MMC_EXT_VIEW_DATA {
  GUID      viewID;
  LPCOLESTR pszURL;
  LPCOLESTR pszViewTitle;
  LPCOLESTR pszTooltipText;
  BOOL      bReplacesDefaultView;
} MMC_EXT_VIEW_DATA, *PMMC_EXT_VIEW_DATA;