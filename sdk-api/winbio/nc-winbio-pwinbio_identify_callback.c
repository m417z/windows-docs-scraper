PWINBIO_IDENTIFY_CALLBACK PwinbioIdentifyCallback;

VOID PwinbioIdentifyCallback(
  [in, optional] PVOID IdentifyCallbackContext,
  [in]           HRESULT OperationStatus,
  [in]           WINBIO_UNIT_ID UnitId,
  [in]           WINBIO_IDENTITY *Identity,
  [in]           WINBIO_BIOMETRIC_SUBTYPE SubFactor,
  [in]           WINBIO_REJECT_DETAIL RejectDetail
)
{...}