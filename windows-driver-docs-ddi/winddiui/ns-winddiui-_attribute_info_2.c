typedef struct _ATTRIBUTE_INFO_2 {
  DWORD dwJobNumberOfPagesPerSide;
  DWORD dwDrvNumberOfPagesPerSide;
  DWORD dwNupBorderFlags;
  DWORD dwJobPageOrderFlags;
  DWORD dwDrvPageOrderFlags;
  DWORD dwJobNumberOfCopies;
  DWORD dwDrvNumberOfCopies;
  DWORD dwColorOptimization;
} ATTRIBUTE_INFO_2, *PATTRIBUTE_INFO_2;