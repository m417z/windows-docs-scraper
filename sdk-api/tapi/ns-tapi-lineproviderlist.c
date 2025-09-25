typedef struct lineproviderlist_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwNumProviders;
  DWORD dwProviderListSize;
  DWORD dwProviderListOffset;
} LINEPROVIDERLIST, *LPLINEPROVIDERLIST;