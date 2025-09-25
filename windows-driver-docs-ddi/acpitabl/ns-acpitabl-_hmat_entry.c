typedef struct _HMAT_ENTRY {
  USHORT Type;
  USHORT Reserved;
  ULONG  Length;
  union {
    struct {
      union {
        struct {
          USHORT ProcessorProximityDomainValid : 1;
          USHORT Reserved0 : 1;
          USHORT Reserved1 : 1;
          USHORT Reserved : 13;
        } DUMMYSTRUCTNAME;
        USHORT AsUSHort;
      } Flags;
      USHORT    Reserved1;
      ULONG     ProcessorProximityDomain;
      ULONG     MemoryProximityDomain;
      ULONG     Reserved2;
      ULONGLONG Reserved3;
      ULONGLONG Reserved4;
    } Msar;
    struct {
      union {
        struct {
          UCHAR MemoryHierarchy : 4;
          UCHAR MinTransferSizeToAchieveValues : 1;
          UCHAR NonSequentialTransfers : 1;
          UCHAR Reserved : 2;
        } DUMMYSTRUCTNAME;
        UCHAR AsUChar;
      } Flags;
      UCHAR     DataType;
      UCHAR     MinTransferSize;
      UCHAR     Reserved1;
      ULONG     NumberOfInitiatorProximityDomains;
      ULONG     NumberOfTargetProximityDomains;
      ULONG     Reserved2;
      ULONGLONG EntryBaseUnit;
    } Sllbi;
    struct {
      ULONG     MemoryProximityDomain;
      ULONG     Reserved1;
      ULONGLONG MemorySideCacheSize;
      union {
        struct {
          ULONG TotalCacheLevels : 4;
          ULONG CacheLevel : 4;
          ULONG CacheAssociativity : 4;
          ULONG WritePolicy : 4;
          ULONG CacheLineSize : 16;
        } DUMMYSTRUCTNAME;
        ULONG AsULong;
      } CacheAttributes;
      USHORT    Reserved2;
      USHORT    NumberOfSmBiosHandles;
    } Msci;
  } DUMMYUNIONNAME;
} HMAT_ENTRY, *PHMAT_ENTRY;