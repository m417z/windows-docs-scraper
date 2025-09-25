typedef struct _WSB_OB_REGISTRATION_INFO {
  LPWSTR  m_wszResourceDLL;
  GUID    m_guidSnapinId;
  DWORD   m_dwProviderName;
  DWORD   m_dwProviderIcon;
  BOOLEAN m_bSupportsRemoting;
} WSB_OB_REGISTRATION_INFO;