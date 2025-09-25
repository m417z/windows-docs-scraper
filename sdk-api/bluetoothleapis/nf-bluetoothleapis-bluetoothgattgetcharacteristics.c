HRESULT BluetoothGATTGetCharacteristics(
  [in]            HANDLE                      hDevice,
  [in, optional]  PBTH_LE_GATT_SERVICE        Service,
  [in]            USHORT                      CharacteristicsBufferCount,
  [out, optional] PBTH_LE_GATT_CHARACTERISTIC CharacteristicsBuffer,
  [out]           USHORT                      *CharacteristicsBufferActual,
  [in]            ULONG                       Flags
);