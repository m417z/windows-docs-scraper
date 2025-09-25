typedef struct _VDS_PORT_PROP {
  VDS_OBJECT_ID   id;
  LPWSTR          pwszFriendlyName;
  LPWSTR          pwszIdentification;
  VDS_PORT_STATUS status;
} VDS_PORT_PROP, *PVDS_PORT_PROP;