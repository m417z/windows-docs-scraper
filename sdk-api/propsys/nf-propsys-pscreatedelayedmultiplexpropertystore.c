PSSTDAPI PSCreateDelayedMultiplexPropertyStore(
        GETPROPERTYSTOREFLAGS        flags,
        IDelayedPropertyStoreFactory *pdpsf,
  [in]  const DWORD                  *rgStoreIds,
  [in]  DWORD                        cStores,
  [in]  REFIID                       riid,
  [out] void                         **ppv
);