typedef struct _CURRENT_INTERNAL_STATUS_PARAMETER_DATA {
  UCHAR Reserved0[4];
  UCHAR IEEECompanyId[4];
  UCHAR CurrentInternalStatusDataSetOneLength[2];
  UCHAR CurrentInternalStatusDataSetTwoLength[2];
  UCHAR CurrentInternalStatusDataSetThreeLength[2];
  UCHAR CurrentInternalStatusDataSetFourLength[4];
  UCHAR Reserved1[364];
  UCHAR NewSavedDataAvailable;
  UCHAR SavedDataGenerationNumber;
  UCHAR CurrentReasonIdentifier[128];
  UCHAR CurrentInternalStatusData[ANYSIZE_ARRAY];
} CURRENT_INTERNAL_STATUS_PARAMETER_DATA, *PCURRENT_INTERNAL_STATUS_PARAMETER_DATA;