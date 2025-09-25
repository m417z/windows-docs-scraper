typedef struct _DHCPCAPI_CLASSID {
  ULONG  Flags;
#if ...
  LPBYTE Data;
#else
  LPBYTE Data;
#endif
  ULONG  nBytesData;
} DHCPCAPI_CLASSID, *PDHCPCAPI_CLASSID, *LPDHCPCAPI_CLASSID;