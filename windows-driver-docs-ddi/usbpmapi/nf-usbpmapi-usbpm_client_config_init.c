VOID USBPM_CLIENT_CONFIG_INIT(
  [Out] PUSBPM_CLIENT_CONFIG            ClientConfig,
  [In]  ULONG                           AccessDesired,
  [In]  PFN_USBPM_EVENT_CALLBACK        EventCallback,
  [In]  PUSBPM_CLIENT_CONFIG_EXTRA_INFO ExtraInfo
);