PSSTDAPI PSCreatePropertyChangeArray(
  [in, optional] const PROPERTYKEY *rgpropkey,
  [in, optional] const PKA_FLAGS   *rgflags,
  [in, optional] const PROPVARIANT *rgpropvar,
  [in]           UINT              cChanges,
  [in]           REFIID            riid,
  [out]          void              **ppv
);