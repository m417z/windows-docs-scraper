NTSTATUS IoCsqInitialize(
  [out] PIO_CSQ                       Csq,
  [in]  PIO_CSQ_INSERT_IRP            CsqInsertIrp,
  [in]  PIO_CSQ_REMOVE_IRP            CsqRemoveIrp,
  [in]  PIO_CSQ_PEEK_NEXT_IRP         CsqPeekNextIrp,
  [in]  PIO_CSQ_ACQUIRE_LOCK          CsqAcquireLock,
  [in]  PIO_CSQ_RELEASE_LOCK          CsqReleaseLock,
  [in]  PIO_CSQ_COMPLETE_CANCELED_IRP CsqCompleteCanceledIrp
);