PWINBIO_EVENT_CALLBACK PwinbioEventCallback;

VOID PwinbioEventCallback(
  [in, optional] PVOID EventCallbackContext,
  [in]           HRESULT OperationStatus,
  [in]           PWINBIO_EVENT Event
)
{...}