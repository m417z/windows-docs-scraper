CMAPI CONFIGRET CM_Get_Device_Interface_ListW(
  [in]           LPGUID      InterfaceClassGuid,
  [in, optional] DEVINSTID_W pDeviceID,
  [out]          PZZWSTR     Buffer,
  [in]           ULONG       BufferLen,
  [in]           ULONG       ulFlags
);