typedef struct _BTH_VENDOR_SPECIFIC_COMMAND {
  ULONG              ManufacturerId;
  UCHAR              LmpVersion;
  BOOLEAN            MatchAnySinglePattern;
  BTH_COMMAND_HEADER HciHeader;
  UCHAR              Data[1];
} BTH_VENDOR_SPECIFIC_COMMAND, *PBTH_VENDOR_SPECIFIC_COMMAND;