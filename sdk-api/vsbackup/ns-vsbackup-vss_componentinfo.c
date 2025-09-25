typedef struct _VSS_COMPONENTINFO {
  VSS_COMPONENT_TYPE type;
  BSTR               bstrLogicalPath;
  BSTR               bstrComponentName;
  BSTR               bstrCaption;
  BYTE               *pbIcon;
  UINT               cbIcon;
  bool               bRestoreMetadata;
  bool               bNotifyOnBackupComplete;
  bool               bSelectable;
  bool               bSelectableForRestore;
  DWORD              dwComponentFlags;
  UINT               cFileCount;
  UINT               cDatabases;
  UINT               cLogFiles;
  UINT               cDependencies;
} VSS_COMPONENTINFO;