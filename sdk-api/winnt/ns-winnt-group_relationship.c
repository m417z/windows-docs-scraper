typedef struct _GROUP_RELATIONSHIP {
  WORD                 MaximumGroupCount;
  WORD                 ActiveGroupCount;
  BYTE                 Reserved[20];
  PROCESSOR_GROUP_INFO GroupInfo[ANYSIZE_ARRAY];
} GROUP_RELATIONSHIP, *PGROUP_RELATIONSHIP;