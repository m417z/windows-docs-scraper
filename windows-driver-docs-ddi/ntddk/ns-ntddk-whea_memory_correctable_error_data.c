typedef struct _WHEA_MEMORY_CORRECTABLE_ERROR_DATA {
  WHEA_MEMORY_CORRECTABLE_ERROR_SECTION_VALIDBITS ValidBits;
  UINT32                                          SocketId;
  UINT32                                          ChannelId;
  UINT32                                          DimmSlot;
  UINT32                                          CorrectableErrorCount;
} WHEA_MEMORY_CORRECTABLE_ERROR_DATA, *PWHEA_MEMORY_CORRECTABLE_ERROR_DATA;