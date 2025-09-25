typedef struct _DXGKARG_CREATEPROCESS {
  [in]  HANDLE                  hDxgkProcess;
  [out] HANDLE                  hKmdProcess;
  [in]  DXGK_CREATEPROCESSFLAGS Flags;
  [in]  UINT                    NumPasid;
  [in]  ULONG                   *pPasid;
  [in]  HANDLE                  hKmdVmWorkerProcess;
  [in]  UINT                    ProcessNameLength;
  [in]  WCHAR                   *pProcessName;
} DXGKARG_CREATEPROCESS;