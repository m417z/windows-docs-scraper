HRESULT OnNewChannelConnection(
  [in]  IWTSVirtualChannel         *pChannel,
  [in]  BSTR                       data,
  [out] BOOL                       *pbAccept,
  [out] IWTSVirtualChannelCallback **ppCallback
);