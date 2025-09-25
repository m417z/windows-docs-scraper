typedef struct _numberfmtA {
  UINT  NumDigits;
  UINT  LeadingZero;
  UINT  Grouping;
  LPSTR lpDecimalSep;
  LPSTR lpThousandSep;
  UINT  NegativeOrder;
} NUMBERFMTA, *LPNUMBERFMTA;