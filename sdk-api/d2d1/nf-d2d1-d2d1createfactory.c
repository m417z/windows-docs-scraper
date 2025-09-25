HRESULT D2D1CreateFactory(
  [in]           D2D1_FACTORY_TYPE          factoryType,
  [in]           REFIID                     riid,
  [in, optional] const D2D1_FACTORY_OPTIONS *pFactoryOptions,
  [out]          void                       **ppIFactory
);