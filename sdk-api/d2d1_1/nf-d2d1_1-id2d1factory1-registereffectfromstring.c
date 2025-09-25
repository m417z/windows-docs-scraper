HRESULT RegisterEffectFromString(
  [in]           REFCLSID                    classId,
  [in]           PCWSTR                      propertyXml,
  [in, optional] const D2D1_PROPERTY_BINDING *bindings,
                 UINT32                      bindingsCount,
                 const PD2D1_EFFECT_FACTORY  effectFactory
);