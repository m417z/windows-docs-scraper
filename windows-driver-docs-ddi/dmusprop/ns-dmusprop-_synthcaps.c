typedef struct _SYNTHCAPS {
  GUID  Guid;
  DWORD Flags;
  DWORD MemorySize;
  DWORD MaxChannelGroups;
  DWORD MaxVoices;
  DWORD MaxAudioChannels;
  DWORD EffectFlags;
  WCHAR Description[128];
} SYNTHCAPS, *PSYNTHCAPS;