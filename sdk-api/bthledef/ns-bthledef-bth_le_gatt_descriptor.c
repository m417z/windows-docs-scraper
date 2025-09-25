typedef struct _BTH_LE_GATT_DESCRIPTOR {
  USHORT                      ServiceHandle;
  USHORT                      CharacteristicHandle;
  BTH_LE_GATT_DESCRIPTOR_TYPE DescriptorType;
  BTH_LE_UUID                 DescriptorUuid;
  USHORT                      AttributeHandle;
} BTH_LE_GATT_DESCRIPTOR, *PBTH_LE_GATT_DESCRIPTOR;