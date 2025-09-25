typedef struct _TC_IFC_DESCRIPTOR {
  ULONG                   Length;
  LPWSTR                  pInterfaceName;
  LPWSTR                  pInterfaceID;
  ADDRESS_LIST_DESCRIPTOR AddressListDesc;
} TC_IFC_DESCRIPTOR, *PTC_IFC_DESCRIPTOR;