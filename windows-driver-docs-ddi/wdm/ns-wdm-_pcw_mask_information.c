typedef struct _PCW_MASK_INFORMATION {
  ULONG64          CounterMask;
  PCUNICODE_STRING InstanceMask;
  ULONG            InstanceId;
  BOOLEAN          CollectMultiple;
  PPCW_BUFFER      Buffer;
  PKEVENT          CancelEvent;
} PCW_MASK_INFORMATION, *PPCW_MASK_INFORMATION;