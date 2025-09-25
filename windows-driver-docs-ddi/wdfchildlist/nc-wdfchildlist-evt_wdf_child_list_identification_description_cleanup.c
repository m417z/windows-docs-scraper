EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP EvtWdfChildListIdentificationDescriptionCleanup;

VOID EvtWdfChildListIdentificationDescriptionCleanup(
  [in]      WDFCHILDLIST ChildList,
  [in, out] PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription
)
{...}