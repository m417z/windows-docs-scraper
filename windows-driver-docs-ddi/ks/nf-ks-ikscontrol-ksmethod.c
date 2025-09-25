NTSTATUS KsMethod(
  [in]      PKSMETHOD Method,
  [in]      ULONG     MethodLength,
  [in, out] PVOID     MethodData,
  [in]      ULONG     DataLength,
  [out]     ULONG     *BytesReturned
);