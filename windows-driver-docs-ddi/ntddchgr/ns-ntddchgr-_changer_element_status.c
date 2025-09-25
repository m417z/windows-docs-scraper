typedef struct _CHANGER_ELEMENT_STATUS {
  CHANGER_ELEMENT Element;
  CHANGER_ELEMENT SrcElementAddress;
  ULONG           Flags;
  ULONG           ExceptionCode;
  UCHAR           TargetId;
  UCHAR           Lun;
  USHORT          Reserved;
  UCHAR           PrimaryVolumeID[MAX_VOLUME_ID_SIZE];
  UCHAR           AlternateVolumeID[MAX_VOLUME_ID_SIZE];
} CHANGER_ELEMENT_STATUS, *PCHANGER_ELEMENT_STATUS;