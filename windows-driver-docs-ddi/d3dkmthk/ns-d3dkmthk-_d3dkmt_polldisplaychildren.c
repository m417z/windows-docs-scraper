typedef struct _D3DKMT_POLLDISPLAYCHILDREN {
  [in] D3DKMT_HANDLE hAdapter;
  [in] UINT          NonDestructiveOnly : 1;
  [in] UINT          SynchronousPolling : 1;
  [in] UINT          DisableModeReset : 1;
  [in] UINT          PollAllAdapters : 1;
  [in] UINT          PollInterruptible : 1;
  [in] UINT          Reserved : 27;
} D3DKMT_POLLDISPLAYCHILDREN;