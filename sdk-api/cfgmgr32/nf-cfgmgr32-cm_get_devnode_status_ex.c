CMAPI CONFIGRET CM_Get_DevNode_Status_Ex(
  [out]          PULONG   pulStatus,
  [out]          PULONG   pulProblemNumber,
  [in]           DEVINST  dnDevInst,
  [in]           ULONG    ulFlags,
  [in, optional] HMACHINE hMachine
);