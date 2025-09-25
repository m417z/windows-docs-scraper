CMAPI CONFIGRET CM_Query_And_Remove_SubTree_ExW(
  [in]            DEVINST        dnAncestor,
  [out, optional] PPNP_VETO_TYPE pVetoType,
  [out, optional] LPWSTR         pszVetoName,
  [in]            ULONG          ulNameLength,
  [in]            ULONG          ulFlags,
  [in, optional]  HMACHINE       hMachine
);