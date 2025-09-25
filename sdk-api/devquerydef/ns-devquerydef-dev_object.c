typedef struct _DEV_OBJECT {
  DEV_OBJECT_TYPE   ObjectType;
  PCWSTR            pszObjectId;
  ULONG             cPropertyCount;
  const DEVPROPERTY *pProperties;
} DEV_OBJECT, *PDEV_OBJECT;