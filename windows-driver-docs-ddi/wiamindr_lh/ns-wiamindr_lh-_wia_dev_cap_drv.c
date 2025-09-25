typedef struct _WIA_DEV_CAP_DRV {
  GUID     *guid;
  ULONG    ulFlags;
  LPOLESTR wszName;
  LPOLESTR wszDescription;
  LPOLESTR wszIcon;
} WIA_DEV_CAP_DRV, *PWIA_DEV_CAP_DRV;