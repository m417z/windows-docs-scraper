typedef struct _FWPS_BIND_REQUEST0 {
  SOCKADDR_STORAGE           localAddressAndPort;
  UINT64                     portReservationToken;
  struct _FWPS_BIND_REQUEST0 *previousVersion;
  UINT64                     modifierFilterId;
} FWPS_BIND_REQUEST0;