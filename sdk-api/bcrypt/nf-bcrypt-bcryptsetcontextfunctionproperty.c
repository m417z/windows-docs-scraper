NTSTATUS BCryptSetContextFunctionProperty(
  [in] ULONG   dwTable,
  [in] LPCWSTR pszContext,
  [in] ULONG   dwInterface,
  [in] LPCWSTR pszFunction,
  [in] LPCWSTR pszProperty,
  [in] ULONG   cbValue,
  [in] PUCHAR  pbValue
);