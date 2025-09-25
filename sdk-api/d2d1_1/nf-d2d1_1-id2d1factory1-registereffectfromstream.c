HRESULT RegisterEffectFromStream(
  [in]           REFCLSID                    classId,
  [in]           IStream                     *propertyXml,
  [in, optional] const D2D1_PROPERTY_BINDING *bindings,
                 UINT32                      bindingsCount,
                 const PD2D1_EFFECT_FACTORY  effectFactory
);