typedef struct _MSiSCSI_PortalInfoClass {
  ULONG            PortalInfoCount;
  ISCSI_PortalInfo PortalInformation[1];
} MSiSCSI_PortalInfoClass, *PMSiSCSI_PortalInfoClass;