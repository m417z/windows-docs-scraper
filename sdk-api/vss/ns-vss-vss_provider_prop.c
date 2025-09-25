typedef struct _VSS_PROVIDER_PROP {
  VSS_ID            m_ProviderId;
  VSS_PWSZ          m_pwszProviderName;
  VSS_PROVIDER_TYPE m_eProviderType;
  VSS_PWSZ          m_pwszProviderVersion;
  VSS_ID            m_ProviderVersionId;
  CLSID             m_ClassId;
} VSS_PROVIDER_PROP, *PVSS_PROVIDER_PROP;