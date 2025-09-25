HRESULT SLLoadApplicationPolicies(
  [in]           const SLID *pApplicationId,
  [in, optional] const SLID *pProductSkuId,
  [in]           DWORD      dwFlags,
  [out]          HSLP       *phPolicyContext
);