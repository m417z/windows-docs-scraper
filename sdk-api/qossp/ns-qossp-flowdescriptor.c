typedef struct _FLOWDESCRIPTOR {
  FLOWSPEC          FlowSpec;
  ULONG             NumFilters;
  LPRSVP_FILTERSPEC FilterList;
} FLOWDESCRIPTOR, *LPFLOWDESCRIPTOR;