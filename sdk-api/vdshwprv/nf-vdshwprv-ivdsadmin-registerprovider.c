HRESULT RegisterProvider(
  [in] VDS_OBJECT_ID     providerId,
  [in] CLSID             providerClsid,
  [in] LPWSTR            pwszName,
  [in] VDS_PROVIDER_TYPE type,
  [in] LPWSTR            pwszMachineName,
  [in] LPWSTR            pwszVersion,
  [in] GUID              guidVersionId
);