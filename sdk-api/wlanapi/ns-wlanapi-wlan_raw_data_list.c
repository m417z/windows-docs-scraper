typedef struct _WLAN_RAW_DATA_LIST {
  DWORD                   dwTotalSize;
  DWORD                   dwNumberOfItems;
  struct {
    DWORD dwDataOffset;
    DWORD dwDataSize;
  };
  __unnamed_struct_0446_1 DataList[1];
} WLAN_RAW_DATA_LIST, *PWLAN_RAW_DATA_LIST;