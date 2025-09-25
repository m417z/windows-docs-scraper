PDEBUG_EXTENSION_KNOWN_STRUCT_EX PdebugExtensionKnownStructEx;

HRESULT PdebugExtensionKnownStructEx(
  [in]                PDEBUG_CLIENT Client,
  [in]                ULONG Flags,
  [in]                ULONG64 Offset,
  [in, optional]      PCSTR TypeName,
  [out, optional]     PSTR Buffer,
  [in, out, optional] PULONG BufferChars
)
{...}