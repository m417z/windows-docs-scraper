typedef struct _UNIFM_HDR {
  DWORD dwSize;
  DWORD dwVersion;
  ULONG ulDefaultCodepage;
  LONG  lGlyphSetDataRCID;
  DWORD loUnidrvInfo;
  DWORD loIFIMetrics;
  DWORD loExtTextMetric;
  DWORD loWidthTable;
  DWORD loKernPair;
  DWORD dwReserved[2];
} UNIFM_HDR, *PUNIFM_HDR;