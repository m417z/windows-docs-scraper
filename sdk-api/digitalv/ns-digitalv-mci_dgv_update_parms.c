typedef struct {
  DWORD_PTR dwCallback;
  POINT     ptOffset;
  POINT     ptExtent;
  RECT      rc;
  HDC       hDC;
  WORD      wReserved0;
} MCI_DGV_UPDATE_PARMS;