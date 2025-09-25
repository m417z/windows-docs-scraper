typedef struct linetranslateoutput_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwDialableStringSize;
  DWORD dwDialableStringOffset;
  DWORD dwDisplayableStringSize;
  DWORD dwDisplayableStringOffset;
  DWORD dwCurrentCountry;
  DWORD dwDestCountry;
  DWORD dwTranslateResults;
} LINETRANSLATEOUTPUT, *LPLINETRANSLATEOUTPUT;