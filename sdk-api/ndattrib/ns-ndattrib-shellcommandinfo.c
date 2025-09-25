typedef struct tagShellCommandInfo {
  LPWSTR pwszOperation;
  LPWSTR pwszFile;
  LPWSTR pwszParameters;
  LPWSTR pwszDirectory;
  ULONG  nShowCmd;
} ShellCommandInfo, *PShellCommandInfo;