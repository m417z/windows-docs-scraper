typedef struct _FILE_LEVEL_TRIM {
  ULONG                 Key;
  ULONG                 NumRanges;
  FILE_LEVEL_TRIM_RANGE Ranges[1];
} FILE_LEVEL_TRIM, *PFILE_LEVEL_TRIM;