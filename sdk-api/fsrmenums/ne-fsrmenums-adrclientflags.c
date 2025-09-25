typedef enum _AdrClientFlags {
  AdrClientFlags_None = 0,
  AdrClientFlags_FailForLocalPaths = 0x1,
  AdrClientFlags_FailIfNotSupportedByServer = 0x2,
  AdrClientFlags_FailIfNotDomainJoined = 0x4
} AdrClientFlags;