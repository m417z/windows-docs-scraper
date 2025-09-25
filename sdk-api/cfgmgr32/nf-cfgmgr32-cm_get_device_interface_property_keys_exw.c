CMAPI CONFIGRET CM_Get_Device_Interface_Property_Keys_ExW(
  [in]            LPCWSTR    pszDeviceInterface,
  [out, optional] DEVPROPKEY *PropertyKeyArray,
  [in, out]       PULONG     PropertyKeyCount,
  [in]            ULONG      ulFlags,
  [in, optional]  HMACHINE   hMachine
);