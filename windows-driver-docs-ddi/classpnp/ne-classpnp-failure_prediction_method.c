typedef enum {
  FailurePredictionNone,
  FailurePredictionIoctl,
  FailurePredictionSmart,
  FailurePredictionSense
} FAILURE_PREDICTION_METHOD, *PFAILURE_PREDICTION_METHOD;