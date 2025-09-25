HRESULT BluetoothGATTGetServices(
  [in]            HANDLE               hDevice,
  [in]            USHORT               ServicesBufferCount,
  [out, optional] PBTH_LE_GATT_SERVICE ServicesBuffer,
  [out]           USHORT               *ServicesBufferActual,
  [in]            ULONG                Flags
);