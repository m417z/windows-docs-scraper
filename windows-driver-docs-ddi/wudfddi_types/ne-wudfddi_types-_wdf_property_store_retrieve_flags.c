typedef enum _WDF_PROPERTY_STORE_RETRIEVE_FLAGS {
  WdfPropertyStoreNormal,
  WdfPropertyStoreCreateIfMissing,
  WdfPropertyStoreCreateVolatile,
  WdfPropertyStoreRetrieveFlagsMask
} WDF_PROPERTY_STORE_RETRIEVE_FLAGS;