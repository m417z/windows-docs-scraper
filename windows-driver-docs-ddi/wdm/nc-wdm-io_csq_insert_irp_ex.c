IO_CSQ_INSERT_IRP_EX IoCsqInsertIrpEx;

NTSTATUS IoCsqInsertIrpEx(
  [in] _IO_CSQ *Csq,
  [in] PIRP Irp,
  [in] PVOID InsertContext
)
{...}