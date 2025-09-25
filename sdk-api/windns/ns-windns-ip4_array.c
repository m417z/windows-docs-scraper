typedef struct _IP4_ARRAY {
  DWORD       AddrCount;
#if ...
  IP4_ADDRESS AddrArray[];
#else
  IP4_ADDRESS AddrArray[1];
#endif
} IP4_ARRAY, *PIP4_ARRAY;