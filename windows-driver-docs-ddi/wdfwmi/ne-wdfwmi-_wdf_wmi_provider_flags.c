typedef enum _WDF_WMI_PROVIDER_FLAGS {
  WdfWmiProviderEventOnly = 0x0001,
  WdfWmiProviderExpensive = 0x0002,
  WdfWmiProviderTracing = 0x0004,
  WdfWmiProviderValidFlags = WdfWmiProviderEventOnly | WdfWmiProviderExpensive | WdfWmiProviderTracing
} WDF_WMI_PROVIDER_FLAGS;