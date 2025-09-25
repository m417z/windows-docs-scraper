typedef struct _MSiSCSI_RedirectPortalInfoClass {
  ULONGLONG                 UniqueAdapterId;
  ULONG                     SessionCount;
  ISCSI_RedirectSessionInfo RedirectSessionList[1];
} MSiSCSI_RedirectPortalInfoClass, *PMSiSCSI_RedirectPortalInfoClass;