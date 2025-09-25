PFNBLUETOOTH_GATT_EVENT_CALLBACK PfnbluetoothGattEventCallback;

VOID PfnbluetoothGattEventCallback(
  [in]           BTH_LE_GATT_EVENT_TYPE EventType,
  [in]           PVOID EventOutParameter,
  [in, optional] PVOID Context
)
{...}