# NfcCxSetLlcpConfig function

## Description

Called by the client driver to configure the LLCP parameters.

## Parameters

### `Device`

A handle to a framework device object.

### `Config`

A pointer to an [NFC_CX_LLCP_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ns-nfccx-_nfc_cx_llcp_config) structure.

## Return value

If the operation succeeds, the function returns STATUS_SUCCESS.

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)