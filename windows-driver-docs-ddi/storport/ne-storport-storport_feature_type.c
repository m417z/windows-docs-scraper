typedef enum _STORPORT_FEATURE_TYPE {
  StorportFeatureBusTypeUnitControl,
  StorportFeatureFruIdUnitControl,
  StorportFeatureFruIdAdapterControl,
  StorportFeatureSetEventLoggingAdapterControl,
  StorportFeatureReportInternalDataUnitControl,
  StorportFeatureReportInternalDataAdapterControl,
  StorportFeatureResetBusSynchronous,
  StorportFeaturePostHwInitialize,
  StorportFeaturePrepareEarlyDumpData,
  StorportFeatureRestoreEarlyDumpData,
  StorportFeatureKsrAdapterPowerDownOptimization,
  StorportFeatureKsrUnitPowerDownOptimization,
  StorportFeaturePreparePLDR,
  StorportFeatureNvmeofAdapterOperation,
  StorportFeatureReserved1,
  StorportFeatureQueryStorMQInterface,
  StorportFeatureMax
} STORPORT_FEATURE_TYPE;