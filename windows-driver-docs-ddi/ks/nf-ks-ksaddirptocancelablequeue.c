KSDDKAPI VOID KsAddIrpToCancelableQueue(
  [in, out]      PLIST_ENTRY           QueueHead,
  [in]           PKSPIN_LOCK           SpinLock,
  [in]           PIRP                  Irp,
  [in]           KSLIST_ENTRY_LOCATION ListLocation,
  [in, optional] PDRIVER_CANCEL        DriverCancel
);