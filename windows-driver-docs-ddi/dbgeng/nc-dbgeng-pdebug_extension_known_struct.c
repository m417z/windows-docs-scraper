PDEBUG_EXTENSION_KNOWN_STRUCT PdebugExtensionKnownStruct;

HRESULT PdebugExtensionKnownStruct(
  [in]      ULONG Flags,
  [in]      ULONG64 Offset,
  [in]      PSTR TypeName,
  [out]     PSTR Buffer,
  [in, out] PULONG BufferChars
)
{...}