ULONG StorPortGetLogicalProcessorRelationship(
  [in]           PVOID                                    HwDeviceExtension,
  [in, optional] PPROCESSOR_NUMBER                        ProcessorNumber,
  [in]           LOGICAL_PROCESSOR_RELATIONSHIP           RelationshipType,
  [out]          PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX Information,
  [in, out]      PULONG                                   Length
);