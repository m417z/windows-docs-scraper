typedef struct CLUS_FORCE_QUORUM_INFO {
  DWORD dwSize;
  DWORD dwNodeBitMask;
  DWORD dwMaxNumberofNodes;
  WCHAR multiszNodeList[1];
} CLUS_FORCE_QUORUM_INFO, *PCLUS_FORCE_QUORUM_INFO;