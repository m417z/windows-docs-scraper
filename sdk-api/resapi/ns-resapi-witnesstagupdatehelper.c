typedef struct _WitnessTagUpdateHelper {
  int             Version;
  PaxosTagCStruct paxosToSet;
  PaxosTagCStruct paxosToValidate;
} WitnessTagUpdateHelper;