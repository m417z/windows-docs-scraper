typedef struct _BTH_LE_UUID {
  BOOLEAN IsShortUuid;
  union {
    USHORT ShortUuid;
    GUID   LongUuid;
  } Value;
} BTH_LE_UUID, *PBTH_LE_UUID;