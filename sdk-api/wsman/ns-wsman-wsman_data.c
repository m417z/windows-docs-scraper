typedef struct _WSMAN_DATA {
  WSManDataType type;
  union {
    WSMAN_DATA_TEXT   text;
    WSMAN_DATA_BINARY binaryData;
    DWORD             number;
  };
} WSMAN_DATA;