typedef struct CONFIRM_CONFLICT_ITEM {
  IShellItem2                *pShellItem;
  LPWSTR                     pszOriginalName;
  LPWSTR                     pszAlternateName;
  LPWSTR                     pszLocationShort;
  LPWSTR                     pszLocationFull;
  SYNCMGR_CONFLICT_ITEM_TYPE nType;
} CONFIRM_CONFLICT_ITEM;