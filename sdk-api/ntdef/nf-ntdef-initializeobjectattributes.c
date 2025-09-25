VOID InitializeObjectAttributes(
  [out]          POBJECT_ATTRIBUTES   p,
  [in]           PUNICODE_STRING      n,
  [in]           ULONG                a,
  [in]           HANDLE               r,
  [in, optional] PSECURITY_DESCRIPTOR s
);