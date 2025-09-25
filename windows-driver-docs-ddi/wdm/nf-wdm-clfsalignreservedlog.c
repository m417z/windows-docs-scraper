CLFSUSER_API NTSTATUS ClfsAlignReservedLog(
  [in]  PVOID       pvMarshalContext,
  [in]  ULONG       cRecords,
  [in]  LONGLONG [] rgcbReservation,
  [out] PLONGLONG   pcbAlignReservation
);