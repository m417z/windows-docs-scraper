typedef enum {
  StorStartDevice,
  StorRemoveDevice,
  StorStopDevice,
  StorQueryCapabilities,
  StorQueryResourceRequirements,
  StorFilterResourceRequirements,
  StorSurpriseRemoval
} STOR_PNP_ACTION, *PSTOR_PNP_ACTION;