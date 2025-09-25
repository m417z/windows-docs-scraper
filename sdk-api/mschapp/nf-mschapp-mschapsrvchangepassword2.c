DWORD MSChapSrvChangePassword2(
  [in] PWSTR                          ServerName,
  [in] PWSTR                          UserName,
  [in] PSAMPR_ENCRYPTED_USER_PASSWORD NewPasswordEncryptedWithOldNt,
  [in] PENCRYPTED_NT_OWF_PASSWORD     OldNtOwfPasswordEncryptedWithNewNt,
  [in] BOOLEAN                        LmPresent,
  [in] PSAMPR_ENCRYPTED_USER_PASSWORD NewPasswordEncryptedWithOldLm,
  [in] PENCRYPTED_LM_OWF_PASSWORD     OldLmOwfPasswordEncryptedWithNewLmOrNt
);