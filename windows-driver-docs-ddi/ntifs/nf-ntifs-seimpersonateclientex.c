NTSTATUS SeImpersonateClientEx(
  [in]           PSECURITY_CLIENT_CONTEXT ClientContext,
  [in, optional] PETHREAD                 ServerThread
);