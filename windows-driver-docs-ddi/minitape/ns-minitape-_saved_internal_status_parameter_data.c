typedef struct _SAVED_INTERNAL_STATUS_PARAMETER_DATA {
  UCHAR Reserved0[4];
  UCHAR IEEECompanyId[4];
  UCHAR SavedInternalStatusDataSetOneLength[2];
  UCHAR SavedInternalStatusDataSetTwoLength[2];
  UCHAR SavedInternalStatusDataSetThreeLength[2];
  UCHAR SavedInternalStatusDataSetFourLength[4];
  UCHAR Reserved1[364];
  UCHAR NewSavedDataAvailable;
  UCHAR SavedDataGenerationNumber;
  UCHAR SavedReasonIdentifier[128];
  UCHAR SavedInternalStatusData[ANYSIZE_ARRAY];
} SAVED_INTERNAL_STATUS_PARAMETER_DATA, *PSAVED_INTERNAL_STATUS_PARAMETER_DATA;