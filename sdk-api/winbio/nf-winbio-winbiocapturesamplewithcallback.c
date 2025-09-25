HRESULT WinBioCaptureSampleWithCallback(
  [in]           WINBIO_SESSION_HANDLE    SessionHandle,
  [in]           WINBIO_BIR_PURPOSE       Purpose,
  [in]           WINBIO_BIR_DATA_FLAGS    Flags,
  [in]           PWINBIO_CAPTURE_CALLBACK CaptureCallback,
  [in, optional] PVOID                    CaptureCallbackContext
);