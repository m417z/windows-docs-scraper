typedef struct tagQuality {
  QualityMessageType Type;
  long               Proportion;
  REFERENCE_TIME     Late;
  REFERENCE_TIME     TimeStamp;
} Quality;