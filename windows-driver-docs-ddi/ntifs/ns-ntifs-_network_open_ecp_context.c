typedef struct _NETWORK_OPEN_ECP_CONTEXT {
  USHORT Size;
  USHORT Reserved;
  struct {
    struct {
      NETWORK_OPEN_LOCATION_QUALIFIER  Location;
      NETWORK_OPEN_INTEGRITY_QUALIFIER Integrity;
      NETWORK_OPEN_IN_FLAGS            Flags;
    } in;
    struct {
      NETWORK_OPEN_LOCATION_QUALIFIER  Location;
      NETWORK_OPEN_INTEGRITY_QUALIFIER Integrity;
      NETWORK_OPEN_OUT_FLAGS           Flags;
    } out;
  } DUMMYSTRUCTNAME;
} NETWORK_OPEN_ECP_CONTEXT, *PNETWORK_OPEN_ECP_CONTEXT;