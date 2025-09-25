typedef struct _RTM_ENTITY_ID {
  union {
    struct {
      ULONG EntityProtocolId;
      ULONG EntityInstanceId;
    };
    ULONGLONG EntityId;
  };
} RTM_ENTITY_ID, *PRTM_ENTITY_ID;