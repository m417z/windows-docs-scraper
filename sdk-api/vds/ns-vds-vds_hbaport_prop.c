typedef struct _VDS_HBAPORT_PROP {
  VDS_OBJECT_ID      id;
  VDS_WWN            wwnNode;
  VDS_WWN            wwnPort;
  VDS_HBAPORT_TYPE   type;
  VDS_HBAPORT_STATUS status;
  ULONG              ulPortSpeed;
  ULONG              ulSupportedPortSpeed;
} VDS_HBAPORT_PROP;