typedef struct _PROCESS_TELEMETRY_ID_INFORMATION {
    ULONG HeaderSize;
    ULONG ProcessId;
    ULONG64 ProcessStartKey;
    ULONG64 CreateTime;
    ULONG64 CreateInterruptTime;
    ULONG64 CreateUnbiasedInterruptTime;
    ULONG64 ProcessSequenceNumber;
    ULONG64 SessionCreateTime;
    ULONG SessionId;
    ULONG BootId;
    ULONG ImageChecksum;
    ULONG ImageTimeDateStamp;
    ULONG UserSidOffset;
    ULONG ImagePathOffset;
    ULONG PackageNameOffset;
    ULONG RelativeAppNameOffset;
    ULONG CommandLineOffset;
} PROCESS_TELEMETRY_ID_INFORMATION, *PPROCESS_TELEMETRY_ID_INFORMATION;