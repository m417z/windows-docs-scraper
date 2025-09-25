KSDDKAPI VOID KsReleaseIrpOnCancelableQueue(
  [in]           PIRP           Irp,
  [in, optional] PDRIVER_CANCEL DriverCancel
);