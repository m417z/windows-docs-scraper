CMAPI CONFIGRET CM_Get_Class_Registry_PropertyA(
  [in]            LPGUID   ClassGuid,
  [in]            ULONG    ulProperty,
  [out, optional] PULONG   pulRegDataType,
  [out]           PVOID    Buffer,
  [in, out]       PULONG   pulLength,
  [in]            ULONG    ulFlags,
  [in, optional]  HMACHINE hMachine
);