typedef struct _SP_PROPSHEETPAGE_REQUEST {
  DWORD            cbSize;
  DWORD            PageRequested;
  HDEVINFO         DeviceInfoSet;
  PSP_DEVINFO_DATA DeviceInfoData;
} SP_PROPSHEETPAGE_REQUEST, *PSP_PROPSHEETPAGE_REQUEST;