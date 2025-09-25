NTSTATUS PoRegisterPowerSettingCallback(
  [in, optional] PDEVICE_OBJECT          DeviceObject,
  [in]           LPCGUID                 SettingGuid,
  [in]           PPOWER_SETTING_CALLBACK Callback,
  [in, optional] PVOID                   Context,
  [out]          PVOID                   *Handle
);