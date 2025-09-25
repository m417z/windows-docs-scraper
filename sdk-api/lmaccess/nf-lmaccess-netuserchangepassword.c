NET_API_STATUS NET_API_FUNCTION NetUserChangePassword(
  [in] LPCWSTR domainname,
  [in] LPCWSTR username,
  [in] LPCWSTR oldpassword,
  [in] LPCWSTR newpassword
);