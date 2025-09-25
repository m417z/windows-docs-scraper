CMAPI CONFIGRET CM_Get_Device_Interface_ListA(
  [in]           LPGUID      InterfaceClassGuid,
  [in, optional] DEVINSTID_A pDeviceID,
  [out]          PZZSTR      Buffer,
  [in]           ULONG       BufferLen,
  [in]           ULONG       ulFlags
);