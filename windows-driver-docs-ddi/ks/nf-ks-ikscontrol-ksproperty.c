NTSTATUS KsProperty(
  [in]      PKSPROPERTY Property,
  [in]      ULONG       PropertyLength,
  [in, out] PVOID       PropertyData,
  [in]      ULONG       DataLength,
  [out]     ULONG       *BytesReturned
);