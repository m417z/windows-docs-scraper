typedef struct linetranslatecaps_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwNumLocations;
  DWORD dwLocationListSize;
  DWORD dwLocationListOffset;
  DWORD dwCurrentLocationID;
  DWORD dwNumCards;
  DWORD dwCardListSize;
  DWORD dwCardListOffset;
  DWORD dwCurrentPreferredCardID;
} LINETRANSLATECAPS, *LPLINETRANSLATECAPS;