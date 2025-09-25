typedef struct D3DDDICB_LOGUMDMARKER {
  [in] HANDLE  hContext;
       UINT64  APISequenceNumber;
       INT     Index;
       INT     StringIndex;
       LPCWSTR Info;
} D3DDDICB_LOGUMDMARKER;