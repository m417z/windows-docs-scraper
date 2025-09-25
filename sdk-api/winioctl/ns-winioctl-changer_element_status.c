typedef struct _CHANGER_ELEMENT_STATUS {
  CHANGER_ELEMENT Element;
  CHANGER_ELEMENT SrcElementAddress;
  DWORD           Flags;
  DWORD           ExceptionCode;
  BYTE            TargetId;
  BYTE            Lun;
  WORD            Reserved;
  BYTE            PrimaryVolumeID[MAX_VOLUME_ID_SIZE];
  BYTE            AlternateVolumeID[MAX_VOLUME_ID_SIZE];
} CHANGER_ELEMENT_STATUS, *PCHANGER_ELEMENT_STATUS;