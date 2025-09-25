HRESULT BluetoothGATTRegisterEvent(
  [in]           HANDLE                           hService,
  [in]           BTH_LE_GATT_EVENT_TYPE           EventType,
  [in]           PVOID                            EventParameterIn,
  [in]           PFNBLUETOOTH_GATT_EVENT_CALLBACK Callback,
  [in, optional] PVOID                            CallbackContext,
  [out]          BLUETOOTH_GATT_EVENT_HANDLE      *pEventHandle,
  [in]           ULONG                            Flags
);