IO_CSQ_PEEK_NEXT_IRP IoCsqPeekNextIrp;

PIRP IoCsqPeekNextIrp(
  [in]           PIO_CSQ Csq,
  [in, optional] PIRP Irp,
  [in, optional] PVOID PeekContext
)
{...}