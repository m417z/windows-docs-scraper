typedef struct _NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY {
  NDIS_OBJECT_HEADER Header;
  UINT32             ElementSize;
  UINT32             NumElements;
  UINT32             NumDestinations;
  PVOID              FirstElement;
} NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY, *PNDIS_SWITCH_FORWARDING_DESTINATION_ARRAY;