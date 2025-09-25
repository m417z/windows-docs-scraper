HRESULT QueueGetValuesByObjectList(
  [in]  IPortableDevicePropVariantCollection  *pObjectIDs,
  [in]  IPortableDeviceKeyCollection          *pKeys,
  [in]  IPortableDevicePropertiesBulkCallback *pCallback,
  [out] GUID                                  *pContext
);