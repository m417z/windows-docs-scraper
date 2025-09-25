NTSTATUS TmCreateEnlistment(
  [out]          PHANDLE            EnlistmentHandle,
  [in]           KPROCESSOR_MODE    PreviousMode,
  [in]           ACCESS_MASK        DesiredAccess,
  [in]           POBJECT_ATTRIBUTES ObjectAttributes,
  [in]           PRKRESOURCEMANAGER ResourceManager,
  [in]           PKTRANSACTION      Transaction,
  [in, optional] ULONG              CreateOptions,
  [in]           NOTIFICATION_MASK  NotificationMask,
  [in, optional] PVOID              EnlistmentKey
);