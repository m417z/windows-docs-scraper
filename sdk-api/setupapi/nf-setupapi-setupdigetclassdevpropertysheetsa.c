WINSETUPAPI BOOL SetupDiGetClassDevPropertySheetsA(
  [in]            HDEVINFO           DeviceInfoSet,
  [in, optional]  PSP_DEVINFO_DATA   DeviceInfoData,
  [in]            LPPROPSHEETHEADERA PropertySheetHeader,
  [in]            DWORD              PropertySheetHeaderPageListSize,
  [out, optional] PDWORD             RequiredSize,
  [in]            DWORD              PropertySheetType
);