PWINBIO_CAPTURE_CALLBACK PwinbioCaptureCallback;

VOID PwinbioCaptureCallback(
  [in, optional] PVOID CaptureCallbackContext,
  [in]           HRESULT OperationStatus,
  [in]           WINBIO_UNIT_ID UnitId,
  [in]           PWINBIO_BIR Sample,
  [in]           SIZE_T SampleSize,
  [in]           WINBIO_REJECT_DETAIL RejectDetail
)
{...}