typedef struct tagDIAGNOSTIC_DATA_SEARCH_CRITERIA {
  LPCWSTR     *producerNames;
  UINT32      producerNameCount;
  LPCWSTR     textToMatch;
  const INT32 *categoryIds;
  UINT32      categoryIdCount;
  const INT32 *privacyTags;
  UINT32      privacyTagCount;
  BOOL        coreDataOnly;
} DIAGNOSTIC_DATA_SEARCH_CRITERIA;