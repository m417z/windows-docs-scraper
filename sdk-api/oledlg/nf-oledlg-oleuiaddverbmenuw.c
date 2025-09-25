BOOL OleUIAddVerbMenuW(
  [in, optional] LPOLEOBJECT lpOleObj,
  [in, optional] LPCWSTR     lpszShortType,
  [in]           HMENU       hMenu,
  [in]           UINT        uPos,
  [in]           UINT        uIDVerbMin,
  [in]           UINT        uIDVerbMax,
  [in]           BOOL        bAddConvert,
  [in]           UINT        idConvert,
  [out]          HMENU       *lphMenu
);