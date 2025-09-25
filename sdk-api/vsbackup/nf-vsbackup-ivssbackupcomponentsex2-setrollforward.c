HRESULT SetRollForward(
  [in] VSS_ID               writerId,
  [in] VSS_COMPONENT_TYPE   ct,
  [in] LPCWSTR              wszLogicalPath,
  [in] LPCWSTR              wszComponentName,
  [in] VSS_ROLLFORWARD_TYPE rollType,
  [in] LPCWSTR              wszRollForwardPoint
);