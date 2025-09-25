# _NFC_CX_CLIENT_CONFIG structure

## Description

The NFC_CX_CLIENT_CONFIG structure is an input parameter to [NfcCxDeviceInitConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/nf-nfccx-nfccxdeviceinitconfig).

## Members

### `Size`

Size of this structure in bytes.

### `IsPowerPolicyOwner`

 A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed enumerator.

### `PowerIdleTimeout`

IdleTimeout value, in milliseconds. Default is 1 second.

### `PowerIdleType`

A [WDF_POWER_POLICY_IDLE_TIMEOUT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_idle_timeout_type)-typed enumerator.

### `BusType`

 An [NFC_CX_TRANSPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ne-nfccx-_nfc_cx_transport_type)-typed enumerator.

### `DriverFlags`

 Combination of [NFC_CX_DRIVER_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ne-nfccx-_nfc_cx_driver_flags) values.

### `DeviceMode`

 Device mode.

### `EvtNfcCxWriteNciPacket`

Pointer to an [EvtNfcCxWriteNciPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/nc-nfccx-evt_nfc_cx_write_nci_packet) callback.

### `EvtNfcCxDeviceIoControl`

Pointer to an [EvtNfcCxDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/nc-nfccx-evt_nfc_cx_device_io_control) callback.

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)