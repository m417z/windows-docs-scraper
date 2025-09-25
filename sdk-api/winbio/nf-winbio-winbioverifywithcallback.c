HRESULT WinBioVerifyWithCallback(
  [in]           WINBIO_SESSION_HANDLE    SessionHandle,
  [in]           WINBIO_IDENTITY          *Identity,
  [in]           WINBIO_BIOMETRIC_SUBTYPE SubFactor,
  [in]           PWINBIO_VERIFY_CALLBACK  VerifyCallback,
  [in, optional] PVOID                    VerifyCallbackContext
);