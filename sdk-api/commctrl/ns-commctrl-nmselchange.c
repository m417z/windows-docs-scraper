typedef struct tagNMSELCHANGE {
  NMHDR      nmhdr;
  SYSTEMTIME stSelStart;
  SYSTEMTIME stSelEnd;
} NMSELCHANGE, *LPNMSELCHANGE;