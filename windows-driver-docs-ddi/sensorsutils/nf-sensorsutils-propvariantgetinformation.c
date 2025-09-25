NTSTATUS PropVariantGetInformation(
  [in]  const PROPVARIANT *PropVariantValue,
  [out] ULONG             *PropVariantOffset,
  [out] ULONG             *PropVariantSize,
  [out] PVOID             *PropVariantPointer,
  [out] DEVPROPTYPE       *RemappedType
);