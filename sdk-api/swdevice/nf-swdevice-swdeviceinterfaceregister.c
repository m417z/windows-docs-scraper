HRESULT SwDeviceInterfaceRegister(
  [in]            HSWDEVICE         hSwDevice,
  [in]            const GUID        *pInterfaceClassGuid,
  [in, optional]  PCWSTR            pszReferenceString,
  [in]            ULONG             cPropertyCount,
  [in, optional]  const DEVPROPERTY *pProperties,
  [in]            BOOL              fEnabled,
  [out, optional] PWSTR             *ppszDeviceInterfaceId
);