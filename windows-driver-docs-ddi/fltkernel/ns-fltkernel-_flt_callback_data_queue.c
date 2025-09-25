typedef struct _FLT_CALLBACK_DATA_QUEUE {
  IO_CSQ                                        Csq;
  FLT_CALLBACK_DATA_QUEUE_FLAGS                 Flags;
  PFLT_INSTANCE                                 Instance;
  PFLT_CALLBACK_DATA_QUEUE_INSERT_IO            InsertIo;
  PFLT_CALLBACK_DATA_QUEUE_REMOVE_IO            RemoveIo;
  PFLT_CALLBACK_DATA_QUEUE_PEEK_NEXT_IO         PeekNextIo;
  PFLT_CALLBACK_DATA_QUEUE_ACQUIRE              Acquire;
  PFLT_CALLBACK_DATA_QUEUE_RELEASE              Release;
  PFLT_CALLBACK_DATA_QUEUE_COMPLETE_CANCELED_IO CompleteCanceledIo;
} FLT_CALLBACK_DATA_QUEUE, *PFLT_CALLBACK_DATA_QUEUE;