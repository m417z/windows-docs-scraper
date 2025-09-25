HRESULT CheckCounter(
  [in]                const D3D11_COUNTER_DESC *pDesc,
  [out]               D3D11_COUNTER_TYPE       *pType,
  [out]               UINT                     *pActiveCounters,
  [out, optional]     LPSTR                    szName,
  [in, out, optional] UINT                     *pNameLength,
  [out, optional]     LPSTR                    szUnits,
  [in, out, optional] UINT                     *pUnitsLength,
  [out, optional]     LPSTR                    szDescription,
  [in, out, optional] UINT                     *pDescriptionLength
);