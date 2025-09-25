NTSTATUS WdfWmiProviderCreate(
  [in]           WDFDEVICE                Device,
  [in]           PWDF_WMI_PROVIDER_CONFIG WmiProviderConfig,
  [in, optional] PWDF_OBJECT_ATTRIBUTES   ProviderAttributes,
  [out]          WDFWMIPROVIDER           *WmiProvider
);