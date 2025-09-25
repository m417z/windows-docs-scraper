NTSTATUS FLTAPI FltCbdqInitialize(
  [in]      PFLT_INSTANCE                                 Instance,
  [in, out] PFLT_CALLBACK_DATA_QUEUE                      Cbdq,
  [in]      PFLT_CALLBACK_DATA_QUEUE_INSERT_IO            CbdqInsertIo,
  [in]      PFLT_CALLBACK_DATA_QUEUE_REMOVE_IO            CbdqRemoveIo,
  [in]      PFLT_CALLBACK_DATA_QUEUE_PEEK_NEXT_IO         CbdqPeekNextIo,
  [in]      PFLT_CALLBACK_DATA_QUEUE_ACQUIRE              CbdqAcquire,
  [in]      PFLT_CALLBACK_DATA_QUEUE_RELEASE              CbdqRelease,
  [in]      PFLT_CALLBACK_DATA_QUEUE_COMPLETE_CANCELED_IO CbdqCompleteCanceledIo
);