NTSTATUS IoRegisterPlugPlayNotification(
  [in]           IO_NOTIFICATION_EVENT_CATEGORY        EventCategory,
  [in]           ULONG                                 EventCategoryFlags,
  [in, optional] PVOID                                 EventCategoryData,
  [in]           PDRIVER_OBJECT                        DriverObject,
  [in]           PDRIVER_NOTIFICATION_CALLBACK_ROUTINE CallbackRoutine,
  [in, optional] __drv_aliasesMem PVOID                Context,
  [out]          PVOID                                 *NotificationEntry
);