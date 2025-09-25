typedef struct _IP_ADAPTER_PREFIX_XP {
  union {
    ULONGLONG Alignment;
    struct {
      ULONG Length;
      DWORD Flags;
    };
  };
  struct _IP_ADAPTER_PREFIX_XP *Next;
  SOCKET_ADDRESS               Address;
  ULONG                        PrefixLength;
} IP_ADAPTER_PREFIX_XP, *PIP_ADAPTER_PREFIX_XP;