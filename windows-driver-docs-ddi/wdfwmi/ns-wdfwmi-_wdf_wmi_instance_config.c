typedef struct _WDF_WMI_INSTANCE_CONFIG {
  ULONG                               Size;
  WDFWMIPROVIDER                      Provider;
  PWDF_WMI_PROVIDER_CONFIG            ProviderConfig;
  BOOLEAN                             UseContextForQuery;
  BOOLEAN                             Register;
  PFN_WDF_WMI_INSTANCE_QUERY_INSTANCE EvtWmiInstanceQueryInstance;
  PFN_WDF_WMI_INSTANCE_SET_INSTANCE   EvtWmiInstanceSetInstance;
  PFN_WDF_WMI_INSTANCE_SET_ITEM       EvtWmiInstanceSetItem;
  PFN_WDF_WMI_INSTANCE_EXECUTE_METHOD EvtWmiInstanceExecuteMethod;
} WDF_WMI_INSTANCE_CONFIG, *PWDF_WMI_INSTANCE_CONFIG;