typedef struct _CHANGER_ELEMENT_STATUS_EX {
  CHANGER_ELEMENT Element;
  CHANGER_ELEMENT SrcElementAddress;
  ULONG           Flags;
  ULONG           ExceptionCode;
  UCHAR           TargetId;
  UCHAR           Lun;
  USHORT          Reserved;
  UCHAR           PrimaryVolumeID[MAX_VOLUME_ID_SIZE];
  UCHAR           AlternateVolumeID[MAX_VOLUME_ID_SIZE];
  UCHAR           VendorIdentification[VENDOR_ID_LENGTH];
  UCHAR           ProductIdentification[PRODUCT_ID_LENGTH];
  UCHAR           SerialNumber[SERIAL_NUMBER_LENGTH];
} CHANGER_ELEMENT_STATUS_EX, *PCHANGER_ELEMENT_STATUS_EX;