typedef struct _PROCESSOR_RELATIONSHIP {
  BYTE           Flags;
  BYTE           EfficiencyClass;
  BYTE           Reserved[20];
  WORD           GroupCount;
  GROUP_AFFINITY GroupMask[ANYSIZE_ARRAY];
} PROCESSOR_RELATIONSHIP, *PPROCESSOR_RELATIONSHIP;