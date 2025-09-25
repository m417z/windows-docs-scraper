SERIALIZEDPROPERTYVALUE * StgConvertVariantToProperty(
  [in]                const PROPVARIANT       *pvar,
  [in]                USHORT                  CodePage,
  [out, optional]     SERIALIZEDPROPERTYVALUE *pprop,
  [in, out]           ULONG                   *pcb,
  [in]                PROPID                  pid,
  [in]                BOOLEAN                 fReserved,
  [in, out, optional] ULONG                   *pcIndirect
);