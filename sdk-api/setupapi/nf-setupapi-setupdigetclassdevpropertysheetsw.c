WINSETUPAPI BOOL SetupDiGetClassDevPropertySheetsW(
  [in]            HDEVINFO           DeviceInfoSet,
  [in, optional]  PSP_DEVINFO_DATA   DeviceInfoData,
  [in]            LPPROPSHEETHEADERW PropertySheetHeader,
  [in]            DWORD              PropertySheetHeaderPageListSize,
  [out, optional] PDWORD             RequiredSize,
  [in]            DWORD              PropertySheetType
);