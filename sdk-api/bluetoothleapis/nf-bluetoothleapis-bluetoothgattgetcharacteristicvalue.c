HRESULT BluetoothGATTGetCharacteristicValue(
  [in]            HANDLE                            hDevice,
  [in]            PBTH_LE_GATT_CHARACTERISTIC       Characteristic,
  [in]            ULONG                             CharacteristicValueDataSize,
  [out, optional] PBTH_LE_GATT_CHARACTERISTIC_VALUE CharacteristicValue,
  [out, optional] USHORT                            *CharacteristicValueSizeRequired,
  [in]            ULONG                             Flags
);