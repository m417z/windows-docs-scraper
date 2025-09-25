typedef struct _PRMT_TABLE {
  DESCRIPTION_HEADER Header;
  GUID               PlatformGuid;
  ULONG              ModuleInfoOffset;
  ULONG              ModuleInfoCount;
} PRMT_TABLE, *PPRMT_TABLE;