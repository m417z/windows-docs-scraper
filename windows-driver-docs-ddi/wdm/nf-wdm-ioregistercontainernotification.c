NTSTATUS
IoRegisterContainerNotification(
    _In_ IO_CONTAINER_NOTIFICATION_CLASS NotificationClass,
    _In_ PIO_CONTAINER_NOTIFICATION_FUNCTION CallbackFunction,
    _In_reads_bytes_opt_(NotificationInformationLength) PVOID NotificationInformation,
    _In_ ULONG NotificationInformationLength,
    _Out_ PVOID * CallbackRegistration
    );