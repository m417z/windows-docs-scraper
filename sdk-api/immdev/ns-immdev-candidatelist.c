typedef struct tagCANDIDATELIST {
  DWORD dwSize;
  DWORD dwStyle;
  DWORD dwCount;
  DWORD dwSelection;
  DWORD dwPageStart;
  DWORD dwPageSize;
  DWORD dwOffset[1];
} CANDIDATELIST, *PCANDIDATELIST, *NPCANDIDATELIST, *LPCANDIDATELIST;