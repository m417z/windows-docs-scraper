typedef struct _MODE_COMMAND_DURATION_LIMIT_PAGE_T2A_SUBPAGE {
  UCHAR                                PageCode : 6;
  UCHAR                                SubPageFormat : 1;
  UCHAR                                PageSavable : 1;
  UCHAR                                SubPageCode;
  UCHAR                                PageLength[2];
  UCHAR                                Reserved[3];
  UCHAR                                Reserved1 : 4;
  UCHAR                                PerfvsCommandDurationGuidelines : 4;
  T2_COMMAND_DURATION_LIMIT_DESCRIPTOR T2CommandDurationLimitDescriptors[DURATION_LIMIT_T2_DESCRIPTOR_COUNT];
} MODE_COMMAND_DURATION_LIMIT_PAGE_T2A_SUBPAGE, *PMODE_COMMAND_DURATION_LIMIT_PAGE_T2A_SUBPAGE;