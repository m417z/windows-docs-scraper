WINSETUPAPI BOOL SetupDiGetDriverInfoDetailW(
  [in]            HDEVINFO                  DeviceInfoSet,
  [in, optional]  PSP_DEVINFO_DATA          DeviceInfoData,
  [in]            PSP_DRVINFO_DATA_W        DriverInfoData,
  [in, out]       PSP_DRVINFO_DETAIL_DATA_W DriverInfoDetailData,
  [in]            DWORD                     DriverInfoDetailDataSize,
  [out, optional] PDWORD                    RequiredSize
);