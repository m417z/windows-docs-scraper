void NdfCreatePnrpIncident(
  [in]           LPCWSTR   cloudname,
  [in, optional] LPCWSTR   peername,
  [in]           BOOL      diagnosePublish,
  [in, optional] LPCWSTR   appId,
  [out]          NDFHANDLE *handle
);