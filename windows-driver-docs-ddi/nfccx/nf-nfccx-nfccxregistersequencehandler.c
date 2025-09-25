NTSTATUS NfcCxRegisterSequenceHandler(
  WDFDEVICE                   Device,
  NFC_CX_SEQUENCE             Sequence,
  PFN_NFC_CX_SEQUENCE_HANDLER EvtNfcCxSequenceHandler
);