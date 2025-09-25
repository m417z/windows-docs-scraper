typedef struct _IP_ADAPTER_MULTICAST_ADDRESS_XP {
  union {
    ULONGLONG Alignment;
    struct {
      ULONG Length;
      DWORD Flags;
    };
  };
  struct _IP_ADAPTER_MULTICAST_ADDRESS_XP *Next;
  SOCKET_ADDRESS                          Address;
} IP_ADAPTER_MULTICAST_ADDRESS_XP, *PIP_ADAPTER_MULTICAST_ADDRESS_XP;