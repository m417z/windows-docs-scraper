DWORD MSChapSrvChangePassword(
  [in] PWSTR            ServerName,
  [in] PWSTR            UserName,
  [in] BOOLEAN          LmOldPresent,
  [in] PLM_OWF_PASSWORD LmOldOwfPassword,
  [in] PLM_OWF_PASSWORD LmNewOwfPassword,
  [in] PNT_OWF_PASSWORD NtOldOwfPassword,
  [in] PNT_OWF_PASSWORD NtNewOwfPassword
);