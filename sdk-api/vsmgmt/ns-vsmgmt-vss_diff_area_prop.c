typedef struct _VSS_DIFF_AREA_PROP {
  VSS_PWSZ m_pwszVolumeName;
  VSS_PWSZ m_pwszDiffAreaVolumeName;
  LONGLONG m_llMaximumDiffSpace;
  LONGLONG m_llAllocatedDiffSpace;
  LONGLONG m_llUsedDiffSpace;
} VSS_DIFF_AREA_PROP, *PVSS_DIFF_AREA_PROP;