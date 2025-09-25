typedef struct _WSB_OB_STATUS_ENTRY {
  DWORD                               m_dwIcon;
  DWORD                               m_dwStatusEntryName;
  DWORD                               m_dwStatusEntryValue;
  ULONG                               m_cValueTypePair;
  WSB_OB_STATUS_ENTRY_VALUE_TYPE_PAIR *m_rgValueTypePair;
} WSB_OB_STATUS_ENTRY;