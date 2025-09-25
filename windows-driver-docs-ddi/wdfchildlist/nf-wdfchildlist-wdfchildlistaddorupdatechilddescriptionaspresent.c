NTSTATUS WdfChildListAddOrUpdateChildDescriptionAsPresent(
  [in]           WDFCHILDLIST                                 ChildList,
  [in]           PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription,
  [in, optional] PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER        AddressDescription
);