DWORD WSManPluginAuthzUserComplete(
  [in]           WSMAN_SENDER_DETAILS *senderDetails,
  [in]           DWORD                flags,
  [in, optional] PVOID                userAuthorizationContext,
  [in, optional] HANDLE               impersonationToken,
  [in]           BOOL                 userIsAdministrator,
  [in]           DWORD                errorCode,
  [in, optional] PCWSTR               extendedErrorInformation
);