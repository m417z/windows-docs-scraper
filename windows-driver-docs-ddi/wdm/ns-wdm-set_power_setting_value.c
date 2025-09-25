typedef struct {
  ULONG                  Version;
  GUID                   Guid;
  SYSTEM_POWER_CONDITION PowerCondition;
  ULONG                  DataLength;
  UCHAR                  Data[ANYSIZE_ARRAY];
} SET_POWER_SETTING_VALUE, *PSET_POWER_SETTING_VALUE;