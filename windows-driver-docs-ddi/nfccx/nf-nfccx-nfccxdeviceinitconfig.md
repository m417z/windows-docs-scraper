# NfcCxDeviceInitConfig function

## Description

Called by the client driver during its AddDevice routine to perform DeviceInit functions. During this process the following I/O callback functions are also exchanged:

* [EvtNfcCxWriteNciPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/nc-nfccx-evt_nfc_cx_write_nci_packet)
* [EvtNfcCxDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/nc-nfccx-evt_nfc_cx_device_io_control)

## Parameters

### `DeviceInit` [in, out]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `Config` [in]

A pointer to an [NFC_CX_CLIENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ns-nfccx-_nfc_cx_client_config) structure.

## Return value

If the operation succeeds, the function returns STATUS_SUCCESS.

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)