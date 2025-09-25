typedef struct PRJ_CALLBACK_DATA {
  UINT32                               Size;
  PRJ_CALLBACK_DATA_FLAGS              Flags;
  PRJ_NAMESPACE_VIRTUALIZATION_CONTEXT NamespaceVirtualizationContext;
  INT32                                CommandId;
  GUID                                 FileId;
  GUID                                 DataStreamId;
  PCWSTR                               FilePathName;
  PRJ_PLACEHOLDER_VERSION_INFO         *VersionInfo;
  UINT32                               TriggeringProcessId;
  PCWSTR                               TriggeringProcessImageFileName;
  void                                 *InstanceContext;
} PRJ_CALLBACK_DATA;