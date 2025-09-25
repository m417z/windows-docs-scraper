typedef struct _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR {
  ULONG                                          SectionOffset;
  ULONG                                          SectionLength;
  WHEA_REVISION                                  Revision;
  WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS ValidBits;
  UCHAR                                          Reserved;
  WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS     Flags;
  GUID                                           SectionType;
  GUID                                           FRUId;
  WHEA_ERROR_SEVERITY                            SectionSeverity;
  CCHAR                                          FRUText[20];
} WHEA_ERROR_RECORD_SECTION_DESCRIPTOR, *PWHEA_ERROR_RECORD_SECTION_DESCRIPTOR;