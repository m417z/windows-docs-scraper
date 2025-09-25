DRMEXPORT HRESULT UDAPICALL DRMAcquireLicense(
  [in] DRMHSESSION hSession,
  [in] UINT        uFlags,
  [in] PWSTR       wszGroupIdentityCredential,
  [in] PWSTR       wszRequestedRights,
  [in] PWSTR       wszCustomData,
  [in] PWSTR       wszURL,
  [in] VOID        *pvContext
);