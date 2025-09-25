typedef struct _ISCSI_RedirectPortalInfo {
  ULONGLONG        UniqueConnectionId;
  ISCSI_IP_Address OriginalIPAddr;
  ULONG            OriginalPort;
  ISCSI_IP_Address RedirectedIPAddr;
  ULONG            RedirectedPort;
  UCHAR            Redirected;
  UCHAR            TemporaryRedirect;
} ISCSI_RedirectPortalInfo, *PISCSI_RedirectPortalInfo;