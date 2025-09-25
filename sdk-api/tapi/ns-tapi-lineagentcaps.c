typedef struct lineagentcaps_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwAgentHandlerInfoSize;
  DWORD dwAgentHandlerInfoOffset;
  DWORD dwCapsVersion;
  DWORD dwFeatures;
  DWORD dwStates;
  DWORD dwNextStates;
  DWORD dwMaxNumGroupEntries;
  DWORD dwAgentStatusMessages;
  DWORD dwNumAgentExtensionIDs;
  DWORD dwAgentExtensionIDListSize;
  DWORD dwAgentExtensionIDListOffset;
  GUID  ProxyGUID;
} LINEAGENTCAPS, *LPLINEAGENTCAPS;