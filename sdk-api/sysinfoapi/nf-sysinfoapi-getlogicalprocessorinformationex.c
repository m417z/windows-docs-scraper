BOOL GetLogicalProcessorInformationEx(
  [in]            LOGICAL_PROCESSOR_RELATIONSHIP           RelationshipType,
  [out, optional] PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX Buffer,
  [in, out]       PDWORD                                   ReturnedLength
);