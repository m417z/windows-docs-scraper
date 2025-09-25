typedef struct _DXGKARG_SETVIRTUALMACHINEDATA {
  HANDLE                       hKmdVmWorkerProcess;
  GUID                         *pVmGuid;
  DXGK_VIRTUALMACHINEDATAFLAGS Flags;
} DXGKARG_SETVIRTUALMACHINEDATA;