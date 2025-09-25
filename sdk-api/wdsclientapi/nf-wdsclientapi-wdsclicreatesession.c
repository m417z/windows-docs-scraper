HRESULT WDSCLIAPI WdsCliCreateSession(
  [in]           PWSTR         pwszServer,
  [in, optional] PWDS_CLI_CRED pCred,
  [out]          PHANDLE       phSession
);