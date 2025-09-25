typedef enum _QOS_FLOWRATE_REASON {
  QOSFlowRateNotApplicable = 0,
  QOSFlowRateContentChange = 1,
  QOSFlowRateCongestion = 2,
  QOSFlowRateHigherContentEncoding = 3,
  QOSFlowRateUserCaused = 4
} QOS_FLOWRATE_REASON, *PQOS_FLOWRATE_REASON;