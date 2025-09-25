CMAPI CONFIGRET CM_Open_Device_Interface_Key_ExA(
  [in]           LPCSTR         pszDeviceInterface,
  [in]           REGSAM         samDesired,
  [in]           REGDISPOSITION Disposition,
  [out]          PHKEY          phkDeviceInterface,
  [in]           ULONG          ulFlags,
  [in, optional] HMACHINE       hMachine
);