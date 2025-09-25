HRESULT CreateListener(
  [in]            const char           *pszChannelName,
  [in]            ULONG                uFlags,
  [in, optional]  IWTSListenerCallback *pListenerCallback,
  [out, optional] IWTSListener         **ppListener
);