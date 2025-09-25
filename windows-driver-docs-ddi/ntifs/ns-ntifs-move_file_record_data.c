typedef struct {
  HANDLE        FileHandle;
  LARGE_INTEGER SourceFileRecord;
  LARGE_INTEGER TargetFileRecord;
} MOVE_FILE_RECORD_DATA, *PMOVE_FILE_RECORD_DATA;