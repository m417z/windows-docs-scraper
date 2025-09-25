typedef enum _LOGICAL_PROCESSOR_RELATIONSHIP {
  RelationProcessorCore,
  RelationNumaNode,
  RelationCache,
  RelationProcessorPackage,
  RelationGroup,
  RelationProcessorDie,
  RelationNumaNodeEx,
  RelationProcessorModule,
  RelationAll = 0xffff
} LOGICAL_PROCESSOR_RELATIONSHIP;