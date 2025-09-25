typedef struct _DXGKARG_COLLECTDIAGNOSTICINFO {
  [in, optional]  HANDLE                   hAdapter;
  [in]            DXGK_DIAGNOSTICINFO_TYPE Type;
                  CHAR                     BucketingString[DXGK_DUMP_BUCKETING_BUFFER_SIZE];
                  CHAR                     DescriptionString[DXGK_DUMP_DESCRIPTION_BUFFER_SIZE];
  union {
    [out, optional] PVOID pReserved;
  };
  [in]            UINT                     BufferSizeIn;
  [out]           UINT                     BufferSizeOut;
  [out]           PVOID                    pBuffer;
} DXGKARG_COLLECTDIAGNOSTICINFO;