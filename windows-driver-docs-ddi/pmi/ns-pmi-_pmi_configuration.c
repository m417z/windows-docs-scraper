typedef struct _PMI_CONFIGURATION {
  ULONG                  Version;
  USHORT                 Size;
  PMI_CONFIGURATION_TYPE ConfigurationType;
  union {
    PMI_MEASUREMENT_CONFIGURATION MeasurementConfiguration;
    PMI_BUDGETING_CONFIGURATION   BudgetingConfiguration;
    PMI_THRESHOLD_CONFIGURATION   ThresholdConfiguration;
  } Configuration;
} PMI_CONFIGURATION, *PPMI_CONFIGURATION;