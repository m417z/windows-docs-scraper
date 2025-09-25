typedef struct tagHH_AKLINK {
  int     cbStruct;
  BOOL    fReserved;
  LPCTSTR pszKeywords;
  LPCTSTR pszUrl;
  LPCTSTR pszMsgText;
  LPCTSTR pszMsgTitle;
  LPCTSTR pszWindow;
  BOOL    fIndexOnFail;
} HH_AKLINK;