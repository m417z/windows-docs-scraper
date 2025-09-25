typedef struct _FORMAT_PARAMETERS {
  MEDIA_TYPE MediaType;
  ULONG      StartCylinderNumber;
  ULONG      EndCylinderNumber;
  ULONG      StartHeadNumber;
  ULONG      EndHeadNumber;
} FORMAT_PARAMETERS, *PFORMAT_PARAMETERS;