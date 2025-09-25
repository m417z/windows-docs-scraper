typedef struct _MSiSCSI_InitiatorNodeFailureEvent {
  ULONGLONG        FailureTime;
  UCHAR            FailureType;
  WCHAR            TargetFailureName[223 + 1];
  ISCSI_IP_Address TargetFailureAddr;
} MSiSCSI_InitiatorNodeFailureEvent, *PMSiSCSI_InitiatorNodeFailureEvent;