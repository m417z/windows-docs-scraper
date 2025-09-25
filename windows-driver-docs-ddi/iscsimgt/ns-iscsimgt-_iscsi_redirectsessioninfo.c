typedef struct _ISCSI_RedirectSessionInfo {
  ULONGLONG                UniqueSessionId;
  ULONG                    TargetPortalGroupTag;
  ULONG                    ConnectionCount;
  ISCSI_RedirectPortalInfo RedirectPortalList[1];
} ISCSI_RedirectSessionInfo, *PISCSI_RedirectSessionInfo;