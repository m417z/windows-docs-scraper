typedef struct _CMP_CONNECT_VER3 {
  IN HANDLE               hOutputPlug;
  IN HANDLE               hInputPlug;
  IN CMP_CONNECT_TYPE     Type;
  IN CIP_DATA_FORMAT_VER3 Format;
  OUT HANDLE              hConnect;
} CMP_CONNECT_VER3, *PCMP_CONNECT_VER3;