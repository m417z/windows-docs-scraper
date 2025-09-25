typedef struct {
  UCHAR                             Generation[4];
  UCHAR                             AdditionalLength[4];
  PRI_FULL_STATUS_DESCRIPTOR_HEADER FullStatusDescriptors[ANYSIZE_ARRAY];
} PRI_FULL_STATUS_LIST, *PPRI_FULL_STATUS_LIST;