typedef struct _FILTER_INITIALIZATION_DATA {
  ULONG                MajorVersion;
  ULONG                MinorVersion;
  PDUMP_START          DumpStart;
  PDUMP_WRITE          DumpWrite;
  PDUMP_FINISH         DumpFinish;
  PDUMP_UNLOAD         DumpUnload;
  PVOID                DumpData;
  ULONG                MaxPagesPerWrite;
  ULONG                Flags;
  PDUMP_READ           DumpRead;
  PDUMP_PRE_READ_WRITE DumpPreReadWrite;
} FILTER_INITIALIZATION_DATA, *PFILTER_INITIALIZATION_DATA;