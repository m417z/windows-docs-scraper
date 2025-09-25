EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP EvtWdfChildListAddressDescriptionCleanup;

VOID EvtWdfChildListAddressDescriptionCleanup(
  [in]      WDFCHILDLIST ChildList,
  [in, out] PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER AddressDescription
)
{...}