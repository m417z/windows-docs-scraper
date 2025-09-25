typedef struct {
  DWORD_PTR dwCallback;
  LPWSTR    lpstrFileName;
  POINT     ptOffset;
  POINT     ptExtent;
  RECT      rc;
} MCI_DGV_CAPTURE_PARMSW;