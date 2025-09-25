PWINBIO_ENROLL_CAPTURE_CALLBACK PwinbioEnrollCaptureCallback;

VOID PwinbioEnrollCaptureCallback(
  [in, optional] PVOID EnrollCallbackContext,
  [in]           HRESULT OperationStatus,
  [in]           WINBIO_REJECT_DETAIL RejectDetail
)
{...}