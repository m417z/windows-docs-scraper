CMAPI CONFIGRET CM_Request_Device_Eject_ExW(
  [in]            DEVINST        dnDevInst,
  [out, optional] PPNP_VETO_TYPE pVetoType,
  [out, optional] LPWSTR         pszVetoName,
  [in]            ULONG          ulNameLength,
  [in]            ULONG          ulFlags,
  [in, optional]  HMACHINE       hMachine
);