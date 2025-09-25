typedef struct RILRADIOCONFIGURATION {
  DWORD                          dwConfigId;
  RILRADIOCONFIGURATIONRADIOTYPE dwRadioType;
  DWORD                          dwSystemTypes[2];
} RILRADIOCONFIGURATION, *LPRILRADIOCONFIGURATION;