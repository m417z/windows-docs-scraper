HRESULT OnAuthenticate(
  [in] COMSVCSEVENTINFO *pInfo,
  [in] REFGUID          guidActivity,
  [in] ULONG64          ObjectID,
  [in] REFGUID          guidIID,
  [in] ULONG            iMeth,
  [in] ULONG            cbByteOrig,
  [in] BYTE             *pSidOriginalUser,
  [in] ULONG            cbByteCur,
  [in] BYTE             *pSidCurrentUser,
  [in] BOOL             bCurrentUserInpersonatingInProc
);