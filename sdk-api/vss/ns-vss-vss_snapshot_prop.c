typedef struct _VSS_SNAPSHOT_PROP {
  VSS_ID             m_SnapshotId;
  VSS_ID             m_SnapshotSetId;
  LONG               m_lSnapshotsCount;
  VSS_PWSZ           m_pwszSnapshotDeviceObject;
  VSS_PWSZ           m_pwszOriginalVolumeName;
  VSS_PWSZ           m_pwszOriginatingMachine;
  VSS_PWSZ           m_pwszServiceMachine;
  VSS_PWSZ           m_pwszExposedName;
  VSS_PWSZ           m_pwszExposedPath;
  VSS_ID             m_ProviderId;
  LONG               m_lSnapshotAttributes;
  VSS_TIMESTAMP      m_tsCreationTimestamp;
  VSS_SNAPSHOT_STATE m_eStatus;
} VSS_SNAPSHOT_PROP, *PVSS_SNAPSHOT_PROP;