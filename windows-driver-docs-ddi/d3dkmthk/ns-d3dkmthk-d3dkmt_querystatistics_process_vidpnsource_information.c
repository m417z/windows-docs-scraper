typedef struct _D3DKMT_QUERYSTATISTICS_PROCESS_VIDPNSOURCE_INFORMATION {
  ULONG                 Frame;
  ULONG                 CancelledFrame;
  ULONG                 QueuedPresent;
  UINT                  Padding;
  D3DKMT_ALIGN64 UINT64 IsVSyncEnabled;
  D3DKMT_ALIGN64 UINT64 VSyncOnTotalTimeMs;
  D3DKMT_ALIGN64 UINT64 VSyncOffKeepPhaseTotalTimeMs;
  D3DKMT_ALIGN64 UINT64 VSyncOffNoPhaseTotalTimeMs;
#if ...
  D3DKMT_ALIGN64 UINT64 Reserved[4];
#else
  D3DKMT_ALIGN64 UINT64 Reserved[8];
#endif
} D3DKMT_QUERYSTATISTICS_PROCESS_VIDPNSOURCE_INFORMATION;