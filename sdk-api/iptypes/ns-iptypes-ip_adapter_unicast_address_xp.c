typedef struct _IP_ADAPTER_UNICAST_ADDRESS_XP {
  union {
    ULONGLONG Alignment;
    struct {
      ULONG Length;
      DWORD Flags;
    };
  };
  struct _IP_ADAPTER_UNICAST_ADDRESS_XP *Next;
  SOCKET_ADDRESS                        Address;
  IP_PREFIX_ORIGIN                      PrefixOrigin;
  IP_SUFFIX_ORIGIN                      SuffixOrigin;
  IP_DAD_STATE                          DadState;
  ULONG                                 ValidLifetime;
  ULONG                                 PreferredLifetime;
  ULONG                                 LeaseLifetime;
} IP_ADAPTER_UNICAST_ADDRESS_XP, *PIP_ADAPTER_UNICAST_ADDRESS_XP;