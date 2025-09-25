typedef struct varstring_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwStringFormat;
  DWORD dwStringSize;
  DWORD dwStringOffset;
} VARSTRING, *LPVARSTRING;