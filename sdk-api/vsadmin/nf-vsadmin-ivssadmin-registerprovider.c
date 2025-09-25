HRESULT RegisterProvider(
  [in] VSS_ID            pProviderId,
  [in] CLSID             ClassId,
  [in] VSS_PWSZ          pwszProviderName,
  [in] VSS_PROVIDER_TYPE eProviderType,
  [in] VSS_PWSZ          pwszProviderVersion,
  [in] VSS_ID            ProviderVersionId
);