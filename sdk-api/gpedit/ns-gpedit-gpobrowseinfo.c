typedef struct tag_GPOBROWSEINFO {
  DWORD                    dwSize;
  DWORD                    dwFlags;
  HWND                     hwndOwner;
  LPOLESTR                 lpTitle;
  LPOLESTR                 lpInitialOU;
  LPOLESTR                 lpDSPath;
  DWORD                    dwDSPathSize;
  LPOLESTR                 lpName;
  DWORD                    dwNameSize;
  GROUP_POLICY_OBJECT_TYPE gpoType;
  GROUP_POLICY_HINT_TYPE   gpoHint;
} GPOBROWSEINFO, *LPGPOBROWSEINFO;