typedef struct _WSK_CLIENT_DISPATCH {
  USHORT               Version;
  USHORT               Reserved;
  PFN_WSK_CLIENT_EVENT WskClientEvent;
} WSK_CLIENT_DISPATCH, *PWSK_CLIENT_DISPATCH;