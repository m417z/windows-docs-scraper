typedef struct _IP_ADAPTER_DNS_SERVER_ADDRESS_XP {
  union {
    ULONGLONG Alignment;
    struct {
      ULONG Length;
      DWORD Reserved;
    };
  };
  struct _IP_ADAPTER_DNS_SERVER_ADDRESS_XP *Next;
  SOCKET_ADDRESS                           Address;
} IP_ADAPTER_DNS_SERVER_ADDRESS_XP, *PIP_ADAPTER_DNS_SERVER_ADDRESS_XP;