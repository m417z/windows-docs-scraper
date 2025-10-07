typedef enum TagUpdateAssessmentStatus { 
      UpdateAssessmentStatus_Latest                    = 0,
      UpdateAssessmentStatus_NotLatestSoftRestriction  = 1,
      UpdateAssessmentStatus_NotLatestHardRestriction  = 2,
      UpdateAssessmentStatus_NotLatestEndOfSupport     = 3,
      UpdateAssessmentStatus_NotLatestServicingTrain   = 4,
      UpdateAssessmentStatus_NotLatestDeferredFeature  = 5,
      UpdateAssessmentStatus_NotLatestDeferredQuality  = 6,
      UpdateAssessmentStatus_NotLatestPausedFeature    = 7,
      UpdateAssessmentStatus_NotLatestPausedQuality    = 8,
      UpdateAssessmentStatus_NotLatestManaged          = 9,
      UpdateAssessmentStatus_NotLatestUnknown          = 10,
      UpdateAssessmentStatus_NotLatestTargetedVersion  = 11
} UpdateAssessmentStatus;