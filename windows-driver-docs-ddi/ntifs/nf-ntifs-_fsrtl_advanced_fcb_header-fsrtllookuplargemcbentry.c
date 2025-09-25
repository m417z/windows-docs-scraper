BOOLEAN FsRtlLookupLargeMcbEntry(
                  PLARGE_MCB Mcb,
                  LONGLONG   Vbn,
                  PLONGLONG  Lbn,
                  PLONGLONG  SectorCountFromLbn,
                  PLONGLONG  StartingLbn,
                  PLONGLONG  SectorCountFromStartingLbn,
  [out, optional] PULONG     Index
);