EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE EvtWdfChildListIdentificationDescriptionCompare;

BOOLEAN EvtWdfChildListIdentificationDescriptionCompare(
  [in] WDFCHILDLIST ChildList,
  [in] PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER FirstIdentificationDescription,
  [in] PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER SecondIdentificationDescription
)
{...}