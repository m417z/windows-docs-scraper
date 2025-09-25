typedef struct _D3DKMT_QUERYSTATISTICS_SEGMENT_INFORMATION {
#if ...
  D3DKMT_ALIGN64 ULONGLONG      CommitLimit;
#if ...
  D3DKMT_ALIGN64 ULONGLONG      BytesCommitted;
#if ...
  D3DKMT_ALIGN64 ULONGLONG      BytesResident;
#else
  ULONG                         CommitLimit;
#endif
#else
  ULONG                         BytesCommitted;
#endif
#else
  ULONG                         BytesResident;
#endif
  D3DKMT_QUERYSTATISTICS_MEMORY Memory;
  ULONG                         Aperture;
  D3DKMT_ALIGN64 ULONGLONG      TotalBytesEvictedByPriority[D3DKMT_QUERYSTATISTICS_ALLOCATION_PRIORITY_CLASS_MAX];
  D3DKMT_ALIGN64 UINT64         SystemMemoryEndAddress;
#if ...
  struct {
    UINT64 PreservedDuringStandby : 1;
    UINT64 PreservedDuringHibernate : 1;
    UINT64 PartiallyPreservedDuringHibernate : 1;
    UINT64 Reserved : 61;
  } D3DKMT_ALIGN64;
  D3DKMT_ALIGN64                PowerFlags;
#else
  struct {
    UINT64 SystemMemory : 1;
    UINT64 PopulatedByReservedDDRByFirmware : 1;
    UINT64 SegmentType : 4;
    UINT64 SegmentGroup : 2;
    UINT64 FullyCPUVisible : 1;
#if ...
    UINT64 Reserved : 55;
#elif
    UINT64 Reserved : 58;
#else
    UINT64 Reserved : 62;
#endif
  } D3DKMT_ALIGN64;
#endif
  D3DKMT_ALIGN64                SegmentProperties;
#if ...
  D3DKMT_ALIGN64 UINT64         Reserved[5];
#elif
  D3DKMT_ALIGN64 UINT64         Reserved[6];
#else
  D3DKMT_ALIGN64 UINT64         Reserved[8];
#endif
} D3DKMT_QUERYSTATISTICS_SEGMENT_INFORMATION;