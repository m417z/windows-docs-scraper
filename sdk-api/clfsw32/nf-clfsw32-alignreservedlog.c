CLFSUSER_API BOOL AlignReservedLog(
  [in, out] PVOID       pvMarshal,
  [in]      ULONG       cReservedRecords,
  [in]      LONGLONG [] rgcbReservation,
  [out]     PLONGLONG   pcbAlignReservation
);