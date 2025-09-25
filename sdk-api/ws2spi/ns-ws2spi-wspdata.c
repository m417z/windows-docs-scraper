typedef struct WSPData {
  WORD  wVersion;
  WORD  wHighVersion;
  WCHAR szDescription[WSPDESCRIPTION_LEN + 1];
} WSPDATA, *LPWSPDATA;