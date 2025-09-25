typedef struct phonebuttoninfo_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwButtonMode;
  DWORD dwButtonFunction;
  DWORD dwButtonTextSize;
  DWORD dwButtonTextOffset;
  DWORD dwDevSpecificSize;
  DWORD dwDevSpecificOffset;
  DWORD dwButtonState;
} PHONEBUTTONINFO, *LPPHONEBUTTONINFO;