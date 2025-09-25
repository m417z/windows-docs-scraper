typedef struct _IP_ADDR_STRING {
  struct _IP_ADDR_STRING *Next;
  IP_ADDRESS_STRING      IpAddress;
  IP_MASK_STRING         IpMask;
  DWORD                  Context;
} IP_ADDR_STRING, *PIP_ADDR_STRING;