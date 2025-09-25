typedef struct _tagCOMPONENT {
  DWORD         dwSize;
  DWORD         dwID;
  int           iComponentType;
  BOOL          fChecked;
  BOOL          fDirty;
  BOOL          fNoScroll;
  COMPPOS       cpPos;
  WCHAR         wszFriendlyName[MAX_PATH];
  WCHAR         wszSource[INTERNET_MAX_URL_LENGTH];
  WCHAR         wszSubscribedURL[INTERNET_MAX_URL_LENGTH];
  DWORD         dwCurItemState;
  COMPSTATEINFO csiOriginal;
  COMPSTATEINFO csiRestored;
} COMPONENT;