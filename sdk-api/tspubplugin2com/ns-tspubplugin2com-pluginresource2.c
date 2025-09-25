typedef struct __MIDL_ItsPubPlugin2_0002 {
  pluginResource                 resourceV1;
  unsigned long                  pceFileAssocListSize;
  pluginResource2FileAssociation *fileAssocList;
  WCHAR                          *securityDescriptor;
  unsigned long                  pceFolderListSize;
  pluginFolderName               *folderList;
} pluginResource2;