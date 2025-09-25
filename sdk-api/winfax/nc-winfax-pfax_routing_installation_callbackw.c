PFAX_ROUTING_INSTALLATION_CALLBACKW PfaxRoutingInstallationCallbackw;

BOOL PfaxRoutingInstallationCallbackw(
  [in]  HANDLE FaxHandle,
  [in]  LPVOID Context,
  [out] LPWSTR MethodName,
  [out] LPWSTR FriendlyName,
  [out] LPWSTR FunctionName,
  [out] LPWSTR Guid
)
{...}