typedef enum _FsrmPropertyConditionType {
  FsrmPropertyConditionType_Unknown = 0,
  FsrmPropertyConditionType_Equal = 1,
  FsrmPropertyConditionType_NotEqual = 2,
  FsrmPropertyConditionType_GreaterThan = 3,
  FsrmPropertyConditionType_LessThan = 4,
  FsrmPropertyConditionType_Contain = 5,
  FsrmPropertyConditionType_Exist = 6,
  FsrmPropertyConditionType_NotExist = 7,
  FsrmPropertyConditionType_StartWith = 8,
  FsrmPropertyConditionType_EndWith = 9,
  FsrmPropertyConditionType_ContainedIn = 10,
  FsrmPropertyConditionType_PrefixOf = 11,
  FsrmPropertyConditionType_SuffixOf = 12,
  FsrmPropertyConditionType_MatchesPattern = 13
} FsrmPropertyConditionType;