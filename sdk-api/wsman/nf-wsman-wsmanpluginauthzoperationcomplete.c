DWORD WSManPluginAuthzOperationComplete(
  [in]           WSMAN_SENDER_DETAILS *senderDetails,
  [in]           DWORD                flags,
  [in, optional] PVOID                userAuthorizationContext,
  [in]           DWORD                errorCode,
  [in, optional] PCWSTR               extendedErrorInformation
);