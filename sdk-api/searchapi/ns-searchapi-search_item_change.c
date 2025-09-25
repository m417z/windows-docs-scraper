typedef struct _SEARCH_ITEM_CHANGE {
  SEARCH_KIND_OF_CHANGE        Change;
  SEARCH_NOTIFICATION_PRIORITY Priority;
  BLOB                         *pUserData;
  LPWSTR                       lpwszURL;
  LPWSTR                       lpwszOldURL;
} SEARCH_ITEM_CHANGE;