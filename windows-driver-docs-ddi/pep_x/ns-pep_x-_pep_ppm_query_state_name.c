typedef struct _PEP_PPM_QUERY_STATE_NAME {
  [in]     ULONG  StateIndex;
  [in/out] USHORT NameSize;
  [in]     PWSTR  Name;
} PEP_PPM_QUERY_STATE_NAME, *PPEP_PPM_QUERY_STATE_NAME;