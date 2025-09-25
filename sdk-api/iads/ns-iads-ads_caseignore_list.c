typedef struct _ADS_CASEIGNORE_LIST {
  struct _ADS_CASEIGNORE_LIST *Next;
  LPWSTR                      String;
} ADS_CASEIGNORE_LIST, *PADS_CASEIGNORE_LIST;