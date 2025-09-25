NDIS_STATUS NdisFRegisterFilterDriver(
  [in]  PDRIVER_OBJECT                      DriverObject,
  [in]  NDIS_HANDLE                         FilterDriverContext,
        PNDIS_FILTER_DRIVER_CHARACTERISTICS FilterDriverCharacteristics,
  [out] PNDIS_HANDLE                        NdisFilterDriverHandle
);