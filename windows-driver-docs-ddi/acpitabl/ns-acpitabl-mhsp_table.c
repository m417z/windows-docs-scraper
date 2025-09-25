typedef struct _MHSP_TABLE {
  DESCRIPTION_HEADER Header;
  UINT32             ProtocolId;
  MHSP_CHANNEL       Channels[4];
} MHSP_TABLE, *PMHSP_TABLE;