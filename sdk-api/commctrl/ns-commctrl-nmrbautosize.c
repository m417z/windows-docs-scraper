typedef struct tagNMRBAUTOSIZE {
  NMHDR hdr;
  BOOL  fChanged;
  RECT  rcTarget;
  RECT  rcActual;
} NMRBAUTOSIZE, *LPNMRBAUTOSIZE;