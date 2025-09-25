USERENVAPI HRESULT RsopSetPolicySettingStatus(
  [in] DWORD                   dwFlags,
  [in] IWbemServices           *pServices,
  [in] IWbemClassObject        *pSettingInstance,
  [in] DWORD                   nInfo,
  [in] POLICYSETTINGSTATUSINFO *pStatus
);