typedef enum _NFC_CX_SEQUENCE {
  SequencePreInit,
  SequenceInitComplete,
  SequencePreRfDiscStart,
  SequenceRfDiscStartComplete,
  SequencePreRfDiscStop,
  SequenceRfDiscStopComplete,
  SequencePreNfceeDisc,
  SequenceNfceeDiscComplete,
  SequencePreShutdown,
  SequenceShutdownComplete,
  SequencePreRecovery,
  SequenceRecoveryComplete,
  SequenceMaximum
} NFC_CX_SEQUENCE, *PNFC_CX_SEQUENCE;