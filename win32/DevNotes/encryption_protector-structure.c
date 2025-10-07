typedef struct _ENCRYPTION_PROTECTOR {
    DWORD TotalLength;
    SID * UserSid;
    PWSTR ProtectorDescriptor;
} ENCRYPTION_PROTECTOR, *PENCRYPTION_PROTECTOR;