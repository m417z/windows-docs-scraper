typedef struct linecountrylist_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwNumCountries;
  DWORD dwCountryListSize;
  DWORD dwCountryListOffset;
} LINECOUNTRYLIST, *LPLINECOUNTRYLIST;