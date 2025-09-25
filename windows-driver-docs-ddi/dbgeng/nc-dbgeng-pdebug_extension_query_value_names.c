PDEBUG_EXTENSION_QUERY_VALUE_NAMES PdebugExtensionQueryValueNames;

HRESULT PdebugExtensionQueryValueNames(
  [in]  PDEBUG_CLIENT Client,
  [in]  ULONG Flags,
  [out] PWSTR Buffer,
  [in]  ULONG BufferChars,
  [out] PULONG BufferNeeded
)
{...}