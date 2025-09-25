typedef struct _IP_ADAPTER_ADDRESSES_XP {
  union {
    ULONGLONG Alignment;
    struct {
      ULONG Length;
      DWORD IfIndex;
    };
  };
  struct _IP_ADAPTER_ADDRESSES_XP   *Next;
  PCHAR                             AdapterName;
  PIP_ADAPTER_UNICAST_ADDRESS_XP    FirstUnicastAddress;
  PIP_ADAPTER_ANYCAST_ADDRESS_XP    FirstAnycastAddress;
  PIP_ADAPTER_MULTICAST_ADDRESS_XP  FirstMulticastAddress;
  PIP_ADAPTER_DNS_SERVER_ADDRESS_XP FirstDnsServerAddress;
  PWCHAR                            DnsSuffix;
  PWCHAR                            Description;
  PWCHAR                            FriendlyName;
  BYTE                              PhysicalAddress[MAX_ADAPTER_ADDRESS_LENGTH];
  DWORD                             PhysicalAddressLength;
  DWORD                             Flags;
  DWORD                             Mtu;
  DWORD                             IfType;
  IF_OPER_STATUS                    OperStatus;
  DWORD                             Ipv6IfIndex;
  DWORD                             ZoneIndices[16];
  PIP_ADAPTER_PREFIX_XP             FirstPrefix;
} IP_ADAPTER_ADDRESSES_XP, *PIP_ADAPTER_ADDRESSES_XP;