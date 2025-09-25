typedef struct _ADS_OCTET_LIST {
  struct _ADS_OCTET_LIST *Next;
  DWORD                  Length;
  BYTE                   *Data;
} ADS_OCTET_LIST, *PADS_OCTET_LIST;