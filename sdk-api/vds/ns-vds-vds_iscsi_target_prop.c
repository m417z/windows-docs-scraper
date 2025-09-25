typedef struct _VDS_ISCSI_TARGET_PROP {
  VDS_OBJECT_ID id;
  LPWSTR        pwszIscsiName;
  LPWSTR        pwszFriendlyName;
  BOOL          bChapEnabled;
} VDS_ISCSI_TARGET_PROP, *PVDS_ISCSI_TARGET_PROP;