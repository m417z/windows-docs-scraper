typedef struct _VSS_DIFF_VOLUME_PROP {
  VSS_PWSZ m_pwszVolumeName;
  VSS_PWSZ m_pwszVolumeDisplayName;
  LONGLONG m_llVolumeFreeSpace;
  LONGLONG m_llVolumeTotalSpace;
} VSS_DIFF_VOLUME_PROP, *PVSS_DIFF_VOLUME_PROP;