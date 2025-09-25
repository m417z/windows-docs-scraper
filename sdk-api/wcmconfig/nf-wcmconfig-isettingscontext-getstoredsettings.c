HRESULT GetStoredSettings(
  [in]  ISettingsIdentity *pIdentity,
  [out] IItemEnumerator   **ppAddedSettings,
  [out] IItemEnumerator   **ppModifiedSettings,
  [out] IItemEnumerator   **ppDeletedSettings
);