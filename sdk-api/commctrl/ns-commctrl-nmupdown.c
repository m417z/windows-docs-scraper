typedef struct _NM_UPDOWN {
  NMHDR hdr;
  int   iPos;
  int   iDelta;
} NMUPDOWN, *LPNMUPDOWN;