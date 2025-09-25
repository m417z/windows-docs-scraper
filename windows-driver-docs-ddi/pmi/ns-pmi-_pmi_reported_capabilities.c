typedef struct _PMI_REPORTED_CAPABILITIES {
  ULONG                Flags;
  PMI_MEASUREMENT_UNIT MeasurementUnit;
  PMI_MEASUREMENT_TYPE MeasurementType;
  ULONG                Accuracy;
  ULONG                SamplingPeriod;
  ULONG                MinimumAverageInterval;
  ULONG                MaximumAverageInterval;
  ULONG                Hysteresis;
  BOOLEAN              Writeable;
  ULONG                MinBudget;
  ULONG                MaxBudget;
  WCHAR                ModelNumber[PMI_NAME_MAX];
  WCHAR                SerialNumber[PMI_NAME_MAX];
  WCHAR                OEMInformation[PMI_NAME_MAX];
} PMI_REPORTED_CAPABILITIES, *PPMI_REPORTED_CAPABILITIES;