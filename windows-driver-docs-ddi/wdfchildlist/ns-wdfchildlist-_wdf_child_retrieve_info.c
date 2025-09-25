typedef struct _WDF_CHILD_RETRIEVE_INFO {
  ULONG                                                 Size;
  PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER          IdentificationDescription;
  PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER                 AddressDescription;
  WDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS                 Status;
  PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE EvtChildListIdentificationDescriptionCompare;
} WDF_CHILD_RETRIEVE_INFO, *PWDF_CHILD_RETRIEVE_INFO;