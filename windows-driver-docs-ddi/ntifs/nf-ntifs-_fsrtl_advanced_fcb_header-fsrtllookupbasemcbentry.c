BOOLEAN FsRtlLookupBaseMcbEntry(
  PBASE_MCB Mcb,
  LONGLONG  Vbn,
  PLONGLONG Lbn,
  PLONGLONG SectorCountFromLbn,
  PLONGLONG StartingLbn,
  PLONGLONG SectorCountFromStartingLbn,
  PULONG    Index
);