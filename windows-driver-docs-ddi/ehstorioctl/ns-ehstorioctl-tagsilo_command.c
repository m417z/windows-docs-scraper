typedef struct tagSILO_COMMAND {
  UCHAR SiloIndex;
  UCHAR Command;
  ULONG cbCommandBuffer;
  UCHAR rgbCommandBuffer[ANYSIZE_ARRAY];
} SILO_COMMAND, *PSILO_COMMAND;