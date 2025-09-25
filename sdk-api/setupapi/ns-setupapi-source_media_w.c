typedef struct _SOURCE_MEDIA_W {
  PCWSTR Reserved;
  PCWSTR Tagfile;
  PCWSTR Description;
  PCWSTR SourcePath;
  PCWSTR SourceFile;
  DWORD  Flags;
} SOURCE_MEDIA_W, *PSOURCE_MEDIA_W;