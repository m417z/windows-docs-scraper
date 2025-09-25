typedef struct _UNIT_ISOCH_PARAMS {
  IN OUT ULONG RX_NumPackets;
  IN OUT ULONG RX_NumDescriptors;
  IN OUT ULONG TX_NumPackets;
  IN OUT ULONG TX_NumDescriptors;
} UNIT_ISOCH_PARAMS, *PUNIT_ISOCH_PARAMS;