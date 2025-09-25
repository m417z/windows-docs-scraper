TRANSLATE_BUS_ADDRESS TranslateBusAddress;

BOOLEAN TranslateBusAddress(
  [in]      PVOID Context,
  [in]      PHYSICAL_ADDRESS BusAddress,
  [in]      ULONG Length,
  [in, out] PULONG AddressSpace,
  [out]     PPHYSICAL_ADDRESS TranslatedAddress
)
{...}