VOID IoCsqInsertIrp(
  [in, out]       PIO_CSQ             Csq,
  [in, out]       PIRP                Irp,
  [out, optional] PIO_CSQ_IRP_CONTEXT Context
);