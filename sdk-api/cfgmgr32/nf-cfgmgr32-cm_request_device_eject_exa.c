CMAPI CONFIGRET CM_Request_Device_Eject_ExA(
  [in]            DEVINST        dnDevInst,
  [out, optional] PPNP_VETO_TYPE pVetoType,
  [out, optional] LPSTR          pszVetoName,
  [in]            ULONG          ulNameLength,
  [in]            ULONG          ulFlags,
  [in, optional]  HMACHINE       hMachine
);