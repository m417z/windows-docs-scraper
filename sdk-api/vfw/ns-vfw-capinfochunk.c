typedef struct tagCapInfoChunk {
  FOURCC fccInfoID;
  LPVOID lpData;
  LONG   cbData;
} CAPINFOCHUNK, *PCAPINFOCHUNK, *LPCAPINFOCHUNK;