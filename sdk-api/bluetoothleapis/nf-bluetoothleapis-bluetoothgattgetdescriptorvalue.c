HRESULT BluetoothGATTGetDescriptorValue(
  [in]            HANDLE                        hDevice,
  [in]            PBTH_LE_GATT_DESCRIPTOR       Descriptor,
  [in]            ULONG                         DescriptorValueDataSize,
  [out, optional] PBTH_LE_GATT_DESCRIPTOR_VALUE DescriptorValue,
  [out, optional] USHORT                        *DescriptorValueSizeRequired,
  [in]            ULONG                         Flags
);