typedef struct _FORMAT_EX_PARAMETERS {
  MEDIA_TYPE MediaType;
  DWORD      StartCylinderNumber;
  DWORD      EndCylinderNumber;
  DWORD      StartHeadNumber;
  DWORD      EndHeadNumber;
  WORD       FormatGapLength;
  WORD       SectorsPerTrack;
  WORD       SectorNumber[1];
} FORMAT_EX_PARAMETERS, *PFORMAT_EX_PARAMETERS;