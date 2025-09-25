WINSETUPAPI BOOL SetupDiGetDriverInfoDetailA(
  [in]            HDEVINFO                  DeviceInfoSet,
  [in, optional]  PSP_DEVINFO_DATA          DeviceInfoData,
  [in]            PSP_DRVINFO_DATA_A        DriverInfoData,
  [in, out]       PSP_DRVINFO_DETAIL_DATA_A DriverInfoDetailData,
  [in]            DWORD                     DriverInfoDetailDataSize,
  [out, optional] PDWORD                    RequiredSize
);