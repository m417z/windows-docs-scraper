typedef struct KNOWNFOLDER_DEFINITION {
  KF_CATEGORY         category;
  LPWSTR              pszName;
  LPWSTR              pszDescription;
  KNOWNFOLDERID       fidParent;
  LPWSTR              pszRelativePath;
  LPWSTR              pszParsingName;
  LPWSTR              pszTooltip;
  LPWSTR              pszLocalizedName;
  LPWSTR              pszIcon;
  LPWSTR              pszSecurity;
  DWORD               dwAttributes;
  KF_DEFINITION_FLAGS kfdFlags;
  FOLDERTYPEID        ftidType;
} KNOWNFOLDER_DEFINITION;