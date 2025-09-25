typedef struct _SES_DOWNLOAD_MICROCODE_STATUS_DIAGNOSTIC_PAGE {
  UCHAR                                    PageCode;
  UCHAR                                    NumberOfSecondarySubEnclosures;
  UCHAR                                    PageLength[2];
  UCHAR                                    GenerationCode[4];
  SES_DOWNLOAD_MICROCODE_STATUS_DESCRIPTOR Descriptors[ANYSIZE_ARRAY];
} SES_DOWNLOAD_MICROCODE_STATUS_DIAGNOSTIC_PAGE, *PSES_DOWNLOAD_MICROCODE_STATUS_DIAGNOSTIC_PAGE;