# SCardTransmit function

## Description

The **SCardTransmit** function sends a service request to the [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and expects to receive data back from the card.

## Parameters

### `hCard` [in]

A reference value returned from
the [SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta) function.

### `pioSendPci` [in]

A pointer to the protocol header structure for the instruction. This buffer is in the format of an [SCARD_IO_REQUEST](https://learn.microsoft.com/windows/desktop/SecAuthN/scard-io-request) structure, followed by the specific protocol control information (PCI).

For the [T=0](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly), [T=1](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly), and Raw protocols, the PCI structure is constant. The [smart card subsystem](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) supplies a global T=0, T=1, or Raw PCI structure, which you can reference by using the symbols SCARD_PCI_T0, SCARD_PCI_T1, and SCARD_PCI_RAW respectively.

### `pbSendBuffer` [in]

A pointer to the actual data to be written to the card.

For T=0, the data parameters are placed into the address pointed to by *pbSendBuffer* according to the following structure:

```cpp
struct {
    BYTE
        bCla,   // the instruction class
        bIns,   // the instruction code
        bP1,    // parameter to the instruction
        bP2,    // parameter to the instruction
        bP3;    // size of I/O transfer
} CmdBytes;

```

The data sent to the card should immediately follow the send buffer. In the special case where no data is sent to the card and no data is expected in return, **bP3** is not sent.

| Member | Meaning |
| --- | --- |
| ****bCla**** | The T=0 instruction class. |
| ****bIns**** | An instruction code in the T=0 instruction class. |
| ****bP1**, **bP2**** | Reference codes that complete the instruction code. |
| ****bP3**** | The number of data bytes to be transmitted during the command, per ISO 7816-4, Section 8.2.1. |

### `cbSendLength` [in]

The length, in bytes, of the *pbSendBuffer* parameter.

For T=0, in the special case where no data is sent to the card and no data expected in return, this length must reflect that the **bP3** member is not being sent; the length should be `sizeof(CmdBytes) - sizeof(BYTE)`.

### `pioRecvPci` [in, out, optional]

Pointer to the protocol header structure for the instruction, followed by a buffer in which to receive any returned protocol control information (PCI) specific to the protocol in use. This parameter can be **NULL** if no PCI is returned.

### `pbRecvBuffer` [out]

Pointer to any data returned from the card.

For T=0, the data is immediately followed by the SW1 and SW2 status bytes. If no data is returned from the card, then this buffer will only contain the SW1 and SW2 status bytes.

### `pcbRecvLength` [in, out]

Supplies the length, in bytes, of the *pbRecvBuffer* parameter and receives the actual number of bytes received from the smart card.

This value cannot be SCARD_AUTOALLOCATE because **SCardTransmit** does not support SCARD_AUTOALLOCATE.

For T=0, the receive buffer must be at least two bytes long to receive the SW1 and SW2 status bytes.

## Return value

If the function successfully sends a service request to the [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), the return value is SCARD_S_SUCCESS.

If the function fails, it returns an error code. For more information, see
[Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values).

## Remarks

The **SCardTransmit** function is a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) access function. For information about other access functions, see
[Smart Card and Reader Access Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-and-reader-access-functions).

For the [T=0 protocol](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly), the data received back are the SW1 and SW2 status codes, possibly preceded by response data. The following paragraphs provide information about the send and receive buffers used to transfer data and issue a command.

#### Examples

The following example shows sending a service request to the smart card.

```cpp
//  Transmit the request.
//  lReturn is of type LONG.
//  hCardHandle was set by a previous call to SCardConnect.
//  pbSend points to the buffer of bytes to send.
//  dwSend is the DWORD value for the number of bytes to send.
//  pbRecv points to the buffer for returned bytes.
//  dwRecv is the DWORD value for the number of returned bytes.
lReturn = SCardTransmit(hCardHandle,
                        SCARD_PCI_T0,
                        pbSend,
                        dwSend,
                        NULL,
                        pbRecv,
                        &dwRecv );
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardTransmit\n");
    exit(1);   // or other appropriate error action
}

```

## See also

[SCARD_IO_REQUEST](https://learn.microsoft.com/windows/desktop/SecAuthN/scard-io-request)

[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta)