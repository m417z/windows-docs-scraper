typedef struct _BLUETOOTH_GATT_VALUE_CHANGED_EVENT {
  USHORT                            ChangedAttributeHandle;
  size_t                            CharacteristicValueDataSize;
  PBTH_LE_GATT_CHARACTERISTIC_VALUE CharacteristicValue;
} BLUETOOTH_GATT_VALUE_CHANGED_EVENT, *PBLUETOOTH_GATT_VALUE_CHANGED_EVENT;