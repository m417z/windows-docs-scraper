typedef struct _BTH_LE_GATT_CHARACTERISTIC {
  USHORT      ServiceHandle;
  BTH_LE_UUID CharacteristicUuid;
  USHORT      AttributeHandle;
  USHORT      CharacteristicValueHandle;
  BOOLEAN     IsBroadcastable;
  BOOLEAN     IsReadable;
  BOOLEAN     IsWritable;
  BOOLEAN     IsWritableWithoutResponse;
  BOOLEAN     IsSignedWritable;
  BOOLEAN     IsNotifiable;
  BOOLEAN     IsIndicatable;
  BOOLEAN     HasExtendedProperties;
} BTH_LE_GATT_CHARACTERISTIC, *PBTH_LE_GATT_CHARACTERISTIC;