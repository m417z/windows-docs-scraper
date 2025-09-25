typedef struct _IP_ADAPTER_UNICAST_ADDRESS_LH {
  union {
    ULONGLONG Alignment;
    struct {
      ULONG Length;
      DWORD Flags;
    };
  };
  struct _IP_ADAPTER_UNICAST_ADDRESS_LH *Next;
  SOCKET_ADDRESS                        Address;
  IP_PREFIX_ORIGIN                      PrefixOrigin;
  IP_SUFFIX_ORIGIN                      SuffixOrigin;
  IP_DAD_STATE                          DadState;
  ULONG                                 ValidLifetime;
  ULONG                                 PreferredLifetime;
  ULONG                                 LeaseLifetime;
  UINT8                                 OnLinkPrefixLength;
} IP_ADAPTER_UNICAST_ADDRESS_LH, *PIP_ADAPTER_UNICAST_ADDRESS_LH;