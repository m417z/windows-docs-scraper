typedef struct _MBB_DEVICE_CONFIG {
  ULONG                                           Size;
  PFN_MBB_DEVICE_SEND_MBIM_FRAGMENT               SendMbimFragment;
  PFN_MBB_DEVICE_RECEIVE_MBIM_FRAGMENT            ReceiveMbimFragment;
  PFN_MBB_DEVICE_SEND_DEVICE_SERVICE_SESSION_DATA SendDeviceServiceSessionData;
  PFN_MBB_DEVICE_CREATE_ADAPTER                   CreateAdapter;
} MBB_DEVICE_CONFIG, *PMBB_DEVICE_CONFIG;