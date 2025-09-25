typedef struct RILOSGEOLOCATIONINFO {
  DWORD                  cbSize;
  DWORD                  dwParams;
  DWORD                  dwLatitude;
  DWORD                  dwLongitude;
  DWORD                  dwAltitude;
  DWORD                  dwAccuracy;
  RILGEOLOCATIONTYPEMASK dwLocationInformationMask;
  RILSYSTEMTIME          stTimeStamp;
  WCHAR                  wszAddressLine1[76];
  WCHAR                  wszAddressLine2[76];
  WCHAR                  wszCity[76];
  WCHAR                  wszState[76];
  WCHAR                  wszCountry[76];
  WCHAR                  wszPostalCode[15];
  WCHAR                  wszFormattedAddress[256];
  WCHAR                  wszCountryCode[11];
  WCHAR                  wszRegionCode[11];
} RILOSGEOLOCATIONINFO, *LPRILOSGEOLOCATIONINFO;