typedef struct _VDS_CONTROLLER_PROP {
  VDS_OBJECT_ID         id;
  LPWSTR                pwszFriendlyName;
  LPWSTR                pwszIdentification;
  VDS_CONTROLLER_STATUS status;
  VDS_HEALTH            health;
  SHORT                 sNumberOfPorts;
} VDS_CONTROLLER_PROP, *PVDS_CONTROLLER_PROP;