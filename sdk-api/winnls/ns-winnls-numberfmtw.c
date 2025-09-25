typedef struct _numberfmtW {
  UINT   NumDigits;
  UINT   LeadingZero;
  UINT   Grouping;
  LPWSTR lpDecimalSep;
  LPWSTR lpThousandSep;
  UINT   NegativeOrder;
} NUMBERFMTW, *LPNUMBERFMTW;