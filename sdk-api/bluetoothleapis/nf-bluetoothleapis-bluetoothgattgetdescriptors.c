HRESULT BluetoothGATTGetDescriptors(
  [in]            HANDLE                      hDevice,
  [in]            PBTH_LE_GATT_CHARACTERISTIC Characteristic,
  [in]            USHORT                      DescriptorsBufferCount,
  [out, optional] PBTH_LE_GATT_DESCRIPTOR     DescriptorsBuffer,
  [out]           USHORT                      *DescriptorsBufferActual,
  [in]            ULONG                       Flags
);