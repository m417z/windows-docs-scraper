CMAPI CONFIGRET CM_Request_Device_EjectA(
  [in]            DEVINST        dnDevInst,
  [out, optional] PPNP_VETO_TYPE pVetoType,
  [out, optional] LPSTR          pszVetoName,
  [in]            ULONG          ulNameLength,
  [in]            ULONG          ulFlags
);