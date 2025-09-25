typedef struct _WDF_CHILD_LIST_CONFIG {
  ULONG                                                   Size;
  ULONG                                                   IdentificationDescriptionSize;
  ULONG                                                   AddressDescriptionSize;
  PFN_WDF_CHILD_LIST_CREATE_DEVICE                        EvtChildListCreateDevice;
  PFN_WDF_CHILD_LIST_SCAN_FOR_CHILDREN                    EvtChildListScanForChildren;
  PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY      EvtChildListIdentificationDescriptionCopy;
  PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_DUPLICATE EvtChildListIdentificationDescriptionDuplicate;
  PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP   EvtChildListIdentificationDescriptionCleanup;
  PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE   EvtChildListIdentificationDescriptionCompare;
  PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY             EvtChildListAddressDescriptionCopy;
  PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_DUPLICATE        EvtChildListAddressDescriptionDuplicate;
  PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP          EvtChildListAddressDescriptionCleanup;
  PFN_WDF_CHILD_LIST_DEVICE_REENUMERATED                  EvtChildListDeviceReenumerated;
} WDF_CHILD_LIST_CONFIG, *PWDF_CHILD_LIST_CONFIG;