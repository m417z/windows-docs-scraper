PDEBUG_EXTENSION_PROVIDE_VALUE PdebugExtensionProvideValue;

HRESULT PdebugExtensionProvideValue(
  [in]  PDEBUG_CLIENT Client,
  [in]  ULONG Flags,
  [in]  PCWSTR Name,
  [out] PULONG64 Value,
  [out] PULONG64 TypeModBase,
  [out] PULONG TypeId,
  [out] PULONG TypeFlags
)
{...}