typedef struct _CSV_DOWN_LEVEL_OPEN_ECP_CONTEXT {
  ULONG                    Version;
  BOOLEAN                  IsResume;
  CSV_DOWN_LEVEL_FILE_TYPE FileType;
  ULONG                    SourceNodeId;
  ULONG                    DestinationNodeId;
} CSV_DOWN_LEVEL_OPEN_ECP_CONTEXT, *PCSV_DOWN_LEVEL_OPEN_ECP_CONTEXT;