HRESULT StartRemoteApplicationEx(
  [in] BSTR         bstrWorkspaceId,
  [in] BSTR         bstrRequestingAppId,
  [in] BSTR         bstrRequestingAppFamilyName,
  [in] VARIANT_BOOL bLaunchIntoImmersiveClient,
  [in] BSTR         bstrImmersiveClientActivationContext,
  [in] SAFEARRAY    *psaParams
);