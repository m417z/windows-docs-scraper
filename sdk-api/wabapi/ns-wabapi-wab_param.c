typedef struct _tagWAB_PARAM {
  ULONG cbSize;
  HWND  hwnd;
  LPSTR szFileName;
  ULONG ulFlags;
  GUID  guidPSExt;
} WAB_PARAM, *LPWAB_PARAM;