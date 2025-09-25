typedef struct _SP_DRVINSTALL_PARAMS {
  DWORD     cbSize;
  DWORD     Rank;
  DWORD     Flags;
  DWORD_PTR PrivateData;
  DWORD     Reserved;
} SP_DRVINSTALL_PARAMS, *PSP_DRVINSTALL_PARAMS;