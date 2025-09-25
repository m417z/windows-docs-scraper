typedef struct POST_UPGRADE_VERSION_INFO {
  DWORD newMajorVersion;
  DWORD newUpgradeVersion;
  DWORD oldMajorVersion;
  DWORD oldUpgradeVersion;
  DWORD reserved;
} POST_UPGRADE_VERSION_INFO, *PPOST_UPGRADE_VERSION_INFO;