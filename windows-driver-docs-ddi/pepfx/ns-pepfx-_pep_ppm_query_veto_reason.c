typedef struct _PEP_PPM_QUERY_VETO_REASON {
  [in]  ULONG  VetoReason;
  [out] USHORT NameSize;
  [in]  PWSTR  Name;
} PEP_PPM_QUERY_VETO_REASON, *PPEP_PPM_QUERY_VETO_REASON;