NTSTATUS SensorCollectionGetAt(
  [in]  UINT32                  Index,
  [in]  PSENSOR_COLLECTION_LIST pSensorsList,
  [out] PROPERTYKEY             *pKey,
  [out] PROPVARIANT             *pValue
);