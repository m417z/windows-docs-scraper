typedef struct _CHANGER_ELEMENT_STATUS_EX {
  CHANGER_ELEMENT Element;
  CHANGER_ELEMENT SrcElementAddress;
  DWORD           Flags;
  DWORD           ExceptionCode;
  BYTE            TargetId;
  BYTE            Lun;
  WORD            Reserved;
  BYTE            PrimaryVolumeID[MAX_VOLUME_ID_SIZE];
  BYTE            AlternateVolumeID[MAX_VOLUME_ID_SIZE];
  BYTE            VendorIdentification[VENDOR_ID_LENGTH];
  BYTE            ProductIdentification[PRODUCT_ID_LENGTH];
  BYTE            SerialNumber[SERIAL_NUMBER_LENGTH];
} CHANGER_ELEMENT_STATUS_EX, *PCHANGER_ELEMENT_STATUS_EX;