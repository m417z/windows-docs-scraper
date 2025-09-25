typedef struct _MSiSCSI_PersistentLogins {
  ULONG                  PersistentLoginCount;
  ULONG                  Reserved;
  ISCSI_Persistent_Login PersistentLogins[1];
} MSiSCSI_PersistentLogins, *PMSiSCSI_PersistentLogins;