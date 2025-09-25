typedef struct _DOT11EXT_IHV_PARAMS {
  DOT11EXT_IHV_PROFILE_PARAMS dot11ExtIhvProfileParams;
  WCHAR                       wstrProfileName[MS_MAX_PROFILE_NAME_LENGTH];
  DWORD                       dwProfileTypeFlags;
  GUID                        interfaceGuid;
} DOT11EXT_IHV_PARAMS, *PDOT11EXT_IHV_PARAMS;