typedef enum _AdrEmailFlags {
  AdrEmailFlags_PutDataOwnerOnToLine = 0x1,
  AdrEmailFlags_PutAdminOnToLine = 0x2,
  AdrEmailFlags_IncludeDeviceClaims = 0x4,
  AdrEmailFlags_IncludeUserInfo = 0x8,
  AdrEmailFlags_GenerateEventLog = 0x10
} AdrEmailFlags;