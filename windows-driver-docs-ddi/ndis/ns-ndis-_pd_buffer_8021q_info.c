typedef struct _PD_BUFFER_8021Q_INFO {
  UINT16 UserPriority : 3;
  UINT16 CanonicalFormatId : 1;
  UINT16 VlanId : 12;
} PD_BUFFER_8021Q_INFO;