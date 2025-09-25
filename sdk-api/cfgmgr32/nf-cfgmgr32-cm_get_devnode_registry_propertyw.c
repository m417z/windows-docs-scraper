CMAPI CONFIGRET CM_Get_DevNode_Registry_PropertyW(
  [in]            DEVINST dnDevInst,
  [in]            ULONG   ulProperty,
  [out, optional] PULONG  pulRegDataType,
  [out, optional] PVOID   Buffer,
  [in, out]       PULONG  pulLength,
  [in]            ULONG   ulFlags
);