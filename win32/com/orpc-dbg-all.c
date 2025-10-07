typedef struct ORPC_DBG_ALL {
  BYTE              *pSignature;
  RPCOLEMESSAGE     *pMessage;
  const IID         *refiid;
  IRpcChannelBuffer *pChannel;
  IUnknown          *pUnkProxyMgr;
  void              *pInterface;
  IUnknown          *pUnkObject;
  HRESULT           hresult;
  void              *pvBuffer;
  ULONG             *cbBuffer;
  ULONG             *lpcbBuffer;
  void              *reserved;
} ORPC_DBG_ALL, *LPORPC_DBG_ALL;