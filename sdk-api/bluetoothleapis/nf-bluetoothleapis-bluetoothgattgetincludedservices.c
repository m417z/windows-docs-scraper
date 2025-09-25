HRESULT BluetoothGATTGetIncludedServices(
  [in]            HANDLE               hDevice,
  [in, optional]  PBTH_LE_GATT_SERVICE ParentService,
  [in]            USHORT               IncludedServicesBufferCount,
  [out, optional] PBTH_LE_GATT_SERVICE IncludedServicesBuffer,
  [out]           USHORT               *IncludedServicesBufferActual,
  [in]            ULONG                Flags
);