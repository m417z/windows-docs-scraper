typedef struct _MSiSCSI_InitiatorSessionInfo {
  ULONGLONG               UniqueAdapterId;
  ULONG                   SessionCount;
  ISCSI_SessionStaticInfo SessionsList[1];
} MSiSCSI_InitiatorSessionInfo, *PMSiSCSI_InitiatorSessionInfo;