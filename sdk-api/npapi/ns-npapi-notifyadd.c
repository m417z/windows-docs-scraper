typedef struct _NOTIFYADD {
  HWND        hwndOwner;
  NETRESOURCE NetResource;
  DWORD       dwAddFlags;
} NOTIFYADD, *LPNOTIFYADD;