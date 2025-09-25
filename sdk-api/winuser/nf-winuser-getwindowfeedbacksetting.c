BOOL GetWindowFeedbackSetting(
  [in]            HWND          hwnd,
  [in]            FEEDBACK_TYPE feedback,
  [in]            DWORD         dwFlags,
  [in, out]       UINT32        *pSize,
  [out, optional] VOID          *config
);