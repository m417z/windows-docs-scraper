HRESULT ColorProfileAddDisplayAssociation(
  WCS_PROFILE_MANAGEMENT_SCOPE scope,
  PCWSTR                       profileName,
  LUID                         targetAdapterID,
  UINT32                       sourceID,
  BOOL                         setAsDefault,
  BOOL                         associateAsAdvancedColor
);