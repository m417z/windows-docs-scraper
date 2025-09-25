HRESULT wiasReadMultiple(
  [in]            BYTE           *pWiasContext,
                  ULONG          ulCount,
  [in]            const PROPSPEC *ps,
  [out]           PROPVARIANT    *pv,
  [out, optional] PROPVARIANT    *pvOld
);