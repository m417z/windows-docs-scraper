typedef struct _WLAN_RAW_DATA {
  DWORD dwDataSize;
#if ...
  BYTE  *DataBlob[];
#else
  BYTE  DataBlob[1];
#endif
} WLAN_RAW_DATA, *PWLAN_RAW_DATA;