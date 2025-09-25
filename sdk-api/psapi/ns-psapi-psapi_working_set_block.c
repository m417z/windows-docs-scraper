typedef union _PSAPI_WORKING_SET_BLOCK {
  ULONG_PTR Flags;
  struct {
    ULONG_PTR Protection : 5;
    ULONG_PTR ShareCount : 3;
    ULONG_PTR Shared : 1;
    ULONG_PTR Reserved : 3;
#if ...
    ULONG_PTR VirtualPage : 52;
#else
    ULONG_PTR VirtualPage : 20;
#endif
  };
} PSAPI_WORKING_SET_BLOCK, *PPSAPI_WORKING_SET_BLOCK;