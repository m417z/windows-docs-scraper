typedef struct __MIDL___MIDL_itf_eventsys_0000_0009_0001 {
  DWORD          cbSize;
  EOC_ChangeType changeType;
  BSTR           objectId;
  BSTR           partitionId;
  BSTR           applicationId;
  GUID           reserved[10];
} COMEVENTSYSCHANGEINFO;