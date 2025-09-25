PWINBIO_VERIFY_CALLBACK PwinbioVerifyCallback;

VOID PwinbioVerifyCallback(
  [in, optional] PVOID VerifyCallbackContext,
  [in]           HRESULT OperationStatus,
  [in]           WINBIO_UNIT_ID UnitId,
  [in]           BOOLEAN Match,
  [in]           WINBIO_REJECT_DETAIL RejectDetail
)
{...}