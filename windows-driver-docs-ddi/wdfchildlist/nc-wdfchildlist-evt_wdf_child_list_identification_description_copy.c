EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY EvtWdfChildListIdentificationDescriptionCopy;

VOID EvtWdfChildListIdentificationDescriptionCopy(
  [in]  WDFCHILDLIST ChildList,
  [in]  PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER SourceIdentificationDescription,
  [out] PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER DestinationIdentificationDescription
)
{...}