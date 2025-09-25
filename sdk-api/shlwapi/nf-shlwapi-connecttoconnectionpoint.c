LWSTDAPI ConnectToConnectionPoint(
  [in, optional]  IUnknown         *punk,
  [in]            REFIID           riidEvent,
                  BOOL             fConnect,
  [in]            IUnknown         *punkTarget,
  [out]           DWORD            *pdwCookie,
  [out, optional] IConnectionPoint **ppcpOut
);