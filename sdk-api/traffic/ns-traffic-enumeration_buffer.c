typedef struct _ENUMERATION_BUFFER {
  ULONG         Length;
  ULONG         OwnerProcessId;
  USHORT        FlowNameLength;
  WCHAR         FlowName[MAX_STRING_LENGTH];
  PTC_GEN_FLOW  pFlow;
  ULONG         NumberOfFilters;
  TC_GEN_FILTER GenericFilter[1];
} ENUMERATION_BUFFER, *PENUMERATION_BUFFER;