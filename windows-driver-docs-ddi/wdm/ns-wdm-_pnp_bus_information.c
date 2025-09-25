typedef struct _PNP_BUS_INFORMATION {
  GUID           BusTypeGuid;
  INTERFACE_TYPE LegacyBusType;
  ULONG          BusNumber;
} PNP_BUS_INFORMATION, *PPNP_BUS_INFORMATION;