BOOL GetCachedSigningLevel(
  [in]                HANDLE File,
  [Out]               PULONG Flags,
  [Out]               PULONG SigningLevel,
  [Out, optional]     PUCHAR Thumbprint,
  [In, Out, optional] PULONG ThumbprintSize,
  [Out, optional]     PULONG ThumbprintAlgorithm
);