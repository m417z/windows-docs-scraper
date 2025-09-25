NET_API_STATUS NET_API_FUNCTION NetValidatePasswordPolicy(
  [in]  LPCWSTR                    ServerName,
  [in]  LPVOID                     Qualifier,
  [in]  NET_VALIDATE_PASSWORD_TYPE ValidationType,
  [in]  LPVOID                     InputArg,
  [out] LPVOID                     *OutputArg
);