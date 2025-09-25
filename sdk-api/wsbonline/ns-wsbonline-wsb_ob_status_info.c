typedef struct _WSB_OB_STATUS_INFO {
  GUID                m_guidSnapinId;
  DWORD               m_cStatusEntry;
  WSB_OB_STATUS_ENTRY *m_rgStatusEntry;
} WSB_OB_STATUS_INFO;