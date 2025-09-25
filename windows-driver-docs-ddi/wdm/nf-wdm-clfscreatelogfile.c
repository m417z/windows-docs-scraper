CLFSUSER_API NTSTATUS ClfsCreateLogFile(
  [out]          PPLOG_FILE_OBJECT    pplfoLog,
  [in]           PUNICODE_STRING      puszLogFileName,
  [in]           ACCESS_MASK          fDesiredAccess,
  [in]           ULONG                dwShareMode,
  [in, optional] PSECURITY_DESCRIPTOR psdLogFile,
  [in]           ULONG                fCreateDisposition,
  [in]           ULONG                fCreateOptions,
  [in]           ULONG                fFlagsAndAttributes,
  [in]           ULONG                fLogOptionFlag,
  [in, optional] PVOID                pvContext,
  [in]           ULONG                cbContext
);