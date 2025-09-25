typedef struct {
  UCHAR ReservationKey[8];
  UCHAR Reserved[4];
  UCHAR ReservationHolder : 1;
  UCHAR AllTargetPorts : 1;
  UCHAR Reserved1 : 6;
  UCHAR Type : 4;
  UCHAR Scope : 4;
  UCHAR Reserved2[4];
  UCHAR RelativeTargetPortIdentifier[2];
  UCHAR AdditionalDescriptorLength[4];
} PRI_FULL_STATUS_DESCRIPTOR_HEADER, *PPRI_FULL_STATUS_DESCRIPTOR_HEADER;