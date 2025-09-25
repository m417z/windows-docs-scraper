EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY EvtWdfChildListAddressDescriptionCopy;

VOID EvtWdfChildListAddressDescriptionCopy(
  [in]  WDFCHILDLIST ChildList,
  [in]  PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER SourceAddressDescription,
  [out] PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER DestinationAddressDescription
)
{...}