HRESULT BluetoothGATTSetCharacteristicValue(
  [in]           HANDLE                             hDevice,
  [in]           PBTH_LE_GATT_CHARACTERISTIC        Characteristic,
  [in]           PBTH_LE_GATT_CHARACTERISTIC_VALUE  CharacteristicValue,
  [in, optional] BTH_LE_GATT_RELIABLE_WRITE_CONTEXT ReliableWriteContext,
  [in]           ULONG                              Flags
);