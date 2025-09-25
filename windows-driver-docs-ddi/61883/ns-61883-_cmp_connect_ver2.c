typedef struct _CMP_CONNECT_VER2 {
  IN HANDLE               hOutputPlug;
  IN HANDLE               hInputPlug;
  IN CMP_CONNECT_TYPE     Type;
  IN CIP_DATA_FORMAT_VER2 Format;
  OUT HANDLE              hConnect;
} CMP_CONNECT_VER2, *PCMP_CONNECT_VER2;