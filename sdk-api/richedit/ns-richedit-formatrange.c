typedef struct _formatrange {
  HDC       hdc;
  HDC       hdcTarget;
  RECT      rc;
  RECT      rcPage;
  CHARRANGE chrg;
} FORMATRANGE;