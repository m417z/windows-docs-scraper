typedef enum WbemComparisonFlagEnum {
  wbemComparisonFlagIncludeAll = 0,
  wbemComparisonFlagIgnoreQualifiers = 0x1,
  wbemComparisonFlagIgnoreObjectSource = 0x2,
  wbemComparisonFlagIgnoreDefaultValues = 0x4,
  wbemComparisonFlagIgnoreClass = 0x8,
  wbemComparisonFlagIgnoreCase = 0x10,
  wbemComparisonFlagIgnoreFlavor = 0x20
} ;