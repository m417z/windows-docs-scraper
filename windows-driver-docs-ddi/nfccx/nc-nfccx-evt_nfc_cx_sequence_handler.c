EVT_NFC_CX_SEQUENCE_HANDLER EvtNfcCxSequenceHandler;

VOID EvtNfcCxSequenceHandler(
  [in]           WDFDEVICE Device,
  [in]           NFC_CX_SEQUENCE Sequence,
  [in]           PFN_NFC_CX_SEQUENCE_COMPLETION_ROUTINE CompletionRoutine,
  [in, optional] WDFCONTEXT CompletionContext
)
{...}