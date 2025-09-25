HRESULT GetRegisteredEffects(
  [out]           CLSID  *effects,
                  UINT32 effectsCount,
  [out]           UINT32 *effectsReturned,
  [out, optional] UINT32 *effectsRegistered
);