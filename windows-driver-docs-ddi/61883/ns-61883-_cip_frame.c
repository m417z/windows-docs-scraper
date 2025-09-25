typedef struct _CIP_FRAME {
  union {
    IN PVOID Reserved;
    IN PVOID pNext;
  };
  IN ULONG                 Flags;
  IN PCIP_VALIDATE_ROUTINE pfnValidate;
  IN PVOID                 ValidateContext;
  IN PCIP_NOTIFY_ROUTINE   pfnNotify;
  IN PVOID                 NotifyContext;
  OUT CYCLE_TIME           Timestamp;
  OUT ULONG                Status;
  IN OUT PUCHAR            Packet;
  OUT ULONG                CompletedBytes;
} CIP_FRAME, *PCIP_FRAME;