CMAPI CONFIGRET CM_Request_Device_EjectW(
  [in]            DEVINST        dnDevInst,
  [out, optional] PPNP_VETO_TYPE pVetoType,
  [out, optional] LPWSTR         pszVetoName,
  [in]            ULONG          ulNameLength,
  [in]            ULONG          ulFlags
);