typedef struct _USB_ROOT_HUB_NAME {
  ULONG ActualLength;
  WCHAR RootHubName[1];
} USB_ROOT_HUB_NAME, *PUSB_ROOT_HUB_NAME;