typedef struct _WINBIO_STORAGE_RECORD {
  PWINBIO_IDENTITY         Identity;
  WINBIO_BIOMETRIC_SUBTYPE SubFactor;
  PULONG                   IndexVector;
  SIZE_T                   IndexElementCount;
  PUCHAR                   TemplateBlob;
  SIZE_T                   TemplateBlobSize;
  PUCHAR                   PayloadBlob;
  SIZE_T                   PayloadBlobSize;
} WINBIO_STORAGE_RECORD, *PWINBIO_STORAGE_RECORD;