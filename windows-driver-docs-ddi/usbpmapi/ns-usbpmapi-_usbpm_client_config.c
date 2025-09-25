typedef struct _USBPM_CLIENT_CONFIG {
  ULONG                           Version;
  ULONG                           AccessDesired;
  PFN_USBPM_EVENT_CALLBACK        EventCallback;
  PVOID                           Context;
  PUSBPM_CLIENT_CONFIG_EXTRA_INFO ExtraInfo;
} USBPM_CLIENT_CONFIG, *PUSBPM_CLIENT_CONFIG;