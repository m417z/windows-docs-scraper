DWORD WSManPluginAuthzQueryQuotaComplete(
  [in]           WSMAN_SENDER_DETAILS *senderDetails,
  [in]           DWORD                flags,
  [in, optional] WSMAN_AUTHZ_QUOTA    *quota,
  [in]           DWORD                errorCode,
  [in, optional] PCWSTR               extendedErrorInformation
);