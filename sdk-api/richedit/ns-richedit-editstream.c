typedef struct _editstream {
  DWORD_PTR          dwCookie;
  DWORD              dwError;
  EDITSTREAMCALLBACK pfnCallback;
} EDITSTREAM;