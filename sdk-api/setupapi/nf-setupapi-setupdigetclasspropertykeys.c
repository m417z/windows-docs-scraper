WINSETUPAPI BOOL SetupDiGetClassPropertyKeys(
  [in]            const GUID *ClassGuid,
  [out, optional] DEVPROPKEY *PropertyKeyArray,
  [in]            DWORD      PropertyKeyCount,
  [out, optional] PDWORD     RequiredPropertyKeyCount,
  [in]            DWORD      Flags
);