NTSTATUS BCryptQueryContextFunctionProperty(
  [in]      ULONG   dwTable,
  [in]      LPCWSTR pszContext,
  [in]      ULONG   dwInterface,
  [in]      LPCWSTR pszFunction,
  [in]      LPCWSTR pszProperty,
  [in, out] ULONG   *pcbValue,
  [in, out] PUCHAR  *ppbValue
);