typedef struct _HID_DESCRIPTOR {
      UCHAR                     bLength;
      UCHAR                     bDescriptorType;
      USHORT                    bcdHID;
      UCHAR                     bCountry;
      UCHAR                     bNumDescriptors;
  struct {
        UCHAR  bReportType;
        USHORT wReportLength;
  } _HID_DESCRIPTOR_DESC_LIST;
      _HID_DESCRIPTOR_DESC_LIST DescriptorList[1];
} HID_DESCRIPTOR, *PHID_DESCRIPTOR;