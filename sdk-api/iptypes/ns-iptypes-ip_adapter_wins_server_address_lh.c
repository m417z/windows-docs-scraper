typedef struct _IP_ADAPTER_WINS_SERVER_ADDRESS_LH {
  union {
    ULONGLONG Alignment;
    struct {
      ULONG Length;
      DWORD Reserved;
    };
  };
  struct _IP_ADAPTER_WINS_SERVER_ADDRESS_LH *Next;
  SOCKET_ADDRESS                            Address;
} IP_ADAPTER_WINS_SERVER_ADDRESS_LH, *PIP_ADAPTER_WINS_SERVER_ADDRESS_LH;