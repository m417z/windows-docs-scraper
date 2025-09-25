typedef struct _IRB_REQ_FREE_ADDRESS_RANGE {
  ULONG          nAddressesToFree;
  PADDRESS_RANGE p1394AddressRange;
  PHANDLE        pAddressRange;
  PVOID          DeviceExtension;
} IRB_REQ_FREE_ADDRESS_RANGE;