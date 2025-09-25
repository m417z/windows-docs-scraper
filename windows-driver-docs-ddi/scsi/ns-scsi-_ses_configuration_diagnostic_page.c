typedef struct _SES_CONFIGURATION_DIAGNOSTIC_PAGE {
  UCHAR                    PageCode;
  UCHAR                    NumberOfSecondarySubEnclosures;
  UCHAR                    PageLength[2];
  UCHAR                    GenerationCode[4];
  SES_ENCLOSURE_DESCRIPTOR Descriptors[ANYSIZE_ARRAY];
} SES_CONFIGURATION_DIAGNOSTIC_PAGE, *PSES_CONFIGURATION_DIAGNOSTIC_PAGE;