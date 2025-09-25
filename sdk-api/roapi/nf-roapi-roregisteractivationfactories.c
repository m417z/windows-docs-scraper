HRESULT RoRegisterActivationFactories(
  [in]  HSTRING                 *activatableClassIds,
  [in]  PFNGETACTIVATIONFACTORY *activationFactoryCallbacks,
  [in]  UINT32                  count,
  [out] RO_REGISTRATION_COOKIE  *cookie
);