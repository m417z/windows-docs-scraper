typedef enum _CLS_LOG_INFORMATION_CLASS {
  ClfsLogBasicInformation,
  ClfsLogBasicInformationPhysical,
  ClfsLogPhysicalNameInformation,
  ClfsLogStreamIdentifierInformation,
  ClfsLogSystemMarkingInformation,
  ClfsLogPhysicalLsnInformation
} CLS_LOG_INFORMATION_CLASS, *PCLS_LOG_INFORMATION_CLASS, PPCLS_LOG_INFORMATION_CLASS;