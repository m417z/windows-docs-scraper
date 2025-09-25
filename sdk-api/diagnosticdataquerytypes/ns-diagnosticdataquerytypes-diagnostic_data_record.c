typedef struct tagDIAGNOSTIC_DATA_RECORD {
  INT64  rowId;
  UINT64 timestamp;
  UINT64 eventKeywords;
  LPWSTR fullEventName;
  LPWSTR providerGroupGuid;
  LPWSTR producerName;
  INT32  *privacyTags;
  UINT32 privacyTagCount;
  INT32  *categoryIds;
  UINT32 categoryIdCount;
  BOOL   isCoreData;
  LPWSTR extra1;
  LPWSTR extra2;
  LPWSTR extra3;
} DIAGNOSTIC_DATA_RECORD;