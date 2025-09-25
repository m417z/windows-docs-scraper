typedef struct _PERSIST_FOLDER_TARGET_INFO {
  PIDLIST_ABSOLUTE pidlTargetFolder;
  WCHAR            szTargetParsingName[260];
  WCHAR            szNetworkProvider[260];
  DWORD            dwAttributes;
  int              csidl;
} PERSIST_FOLDER_TARGET_INFO;