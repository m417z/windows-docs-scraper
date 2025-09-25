typedef struct _VDS_PATH_INFO {
  VDS_PATH_ID         pathId;
  VDS_HWPROVIDER_TYPE type;
  VDS_PATH_STATUS     status;
  union {
    VDS_OBJECT_ID controllerPortId;
    VDS_OBJECT_ID targetPortalId;
  };
  union {
    VDS_OBJECT_ID hbaPortId;
    VDS_OBJECT_ID initiatorAdapterId;
  };
  union {
    VDS_HBAPORT_PROP *pHbaPortProp;
    VDS_IPADDRESS    *pInitiatorPortalIpAddr;
  };
} VDS_PATH_INFO;