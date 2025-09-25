typedef struct _SEARCH_ITEM_PERSISTENT_CHANGE {
  SEARCH_KIND_OF_CHANGE        Change;
  LPWSTR                       URL;
  LPWSTR                       OldURL;
  SEARCH_NOTIFICATION_PRIORITY Priority;
} SEARCH_ITEM_PERSISTENT_CHANGE;