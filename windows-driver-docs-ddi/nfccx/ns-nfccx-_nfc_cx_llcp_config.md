# _NFC_CX_LLCP_CONFIG structure

## Description

The NFC_CX_LLCP_CONFIG structure is an input parameter to [NfcCxSetLlcpConfig.](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/nf-nfccx-nfccxsetllcpconfig)

## Members

### `Size`

 Size of this structure in bytes.

### `Miu`

Max information unit in bytes. Default is 1024.

### `LinkTimeout`

 LTO timeout in multiples of 10 milliseconds. Default is 100 (1 second).

### `RecvWindowSize`

The receive window size per LLCP spec. Default value is 5.

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)