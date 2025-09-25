typedef struct _VSS_VOLUME_PROTECTION_INFO {
  VSS_PROTECTION_LEVEL m_protectionLevel;
  BOOL                 m_volumeIsOfflineForProtection;
  VSS_PROTECTION_FAULT m_protectionFault;
  LONG                 m_failureStatus;
  BOOL                 m_volumeHasUnusedDiffArea;
  DWORD                m_reserved;
} VSS_VOLUME_PROTECTION_INFO, *PVSS_VOLUME_PROTECTION_INFO;