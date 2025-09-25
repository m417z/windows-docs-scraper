typedef struct _BTH_PROFILE_DRIVER_INTERFACE {
  INTERFACE                             Interface;
  PFNBTH_ALLOCATE_BRB                   BthAllocateBrb;
  PFNBTH_FREE_BRB                       BthFreeBrb;
  PFNBTH_INITIALIZE_BRB                 BthInitializeBrb;
  PFNBTH_REUSE_BRB                      BthReuseBrb;
  PFNBTH_IS_BLUETOOTH_VERSION_AVAILABLE IsBluetoothVersionAvailable;
} BTH_PROFILE_DRIVER_INTERFACE, *PBTH_PROFILE_DRIVER_INTERFACE;