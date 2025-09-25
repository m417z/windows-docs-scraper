typedef struct __MIDL_ItsPubPlugin_0001 {
  WCHAR         alias[256];
  WCHAR         name[256];
  WCHAR         *resourceFileContents;
  WCHAR         fileExtension[256];
  WCHAR         resourcePluginType[256];
  boolean       isDiscoverable;
  long          resourceType;
  unsigned long pceIconSize;
  byte          *iconContents;
  unsigned long pcePluginBlobSize;
  byte          *blobContents;
} pluginResource;