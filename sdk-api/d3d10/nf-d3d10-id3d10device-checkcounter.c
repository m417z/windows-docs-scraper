HRESULT CheckCounter(
  [in]      const D3D10_COUNTER_DESC *pDesc,
  [out]     D3D10_COUNTER_TYPE       *pType,
  [out]     UINT                     *pActiveCounters,
  [out]     LPSTR                    szName,
  [in, out] UINT                     *pNameLength,
  [out]     LPSTR                    szUnits,
  [in, out] UINT                     *pUnitsLength,
  [out]     LPSTR                    szDescription,
  [in, out] UINT                     *pDescriptionLength
);