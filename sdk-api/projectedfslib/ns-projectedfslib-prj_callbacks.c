typedef struct PRJ_CALLBACKS {
  PRJ_START_DIRECTORY_ENUMERATION_CB *StartDirectoryEnumerationCallback;
  PRJ_END_DIRECTORY_ENUMERATION_CB   *EndDirectoryEnumerationCallback;
  PRJ_GET_DIRECTORY_ENUMERATION_CB   *GetDirectoryEnumerationCallback;
  PRJ_GET_PLACEHOLDER_INFO_CB        *GetPlaceholderInfoCallback;
  PRJ_GET_FILE_DATA_CB               *GetFileDataCallback;
  PRJ_QUERY_FILE_NAME_CB             *QueryFileNameCallback;
  PRJ_NOTIFICATION_CB                *NotificationCallback;
  PRJ_CANCEL_COMMAND_CB              *CancelCommandCallback;
} PRJ_CALLBACKS;