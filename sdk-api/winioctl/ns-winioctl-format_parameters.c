typedef struct _FORMAT_PARAMETERS {
  MEDIA_TYPE MediaType;
  DWORD      StartCylinderNumber;
  DWORD      EndCylinderNumber;
  DWORD      StartHeadNumber;
  DWORD      EndHeadNumber;
} FORMAT_PARAMETERS, *PFORMAT_PARAMETERS;