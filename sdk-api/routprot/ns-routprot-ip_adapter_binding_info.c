typedef struct IP_ADAPTER_BINDING_INFO {
  ULONG            AddressCount;
  DWORD            RemoteAddress;
  ULONG            Mtu;
  ULONGLONG        Speed;
  IP_LOCAL_BINDING Address[0];
} IP_ADAPTER_BINDING_INFO, *PIP_ADAPTER_BINDING_INFO;