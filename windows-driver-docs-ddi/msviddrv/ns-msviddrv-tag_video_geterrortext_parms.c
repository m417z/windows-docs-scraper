typedef struct tag_video_geterrortext_parms {
  DWORD  dwError;
#if ...
  LPWSTR lpText;
#else
  LPSTR  lpText;
#endif
  DWORD  dwLength;
} VIDEO_GETERRORTEXT_PARMS, *LPVIDEO_GETERRORTEXT_PARMS;