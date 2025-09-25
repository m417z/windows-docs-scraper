# SCardGetAttrib function

## Description

The **SCardGetAttrib** function retrieves the current reader attributes for the given handle. It does not affect the [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), driver, or [card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `hCard` [in]

Reference value returned from [SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta).

### `dwAttrId` [in]

Identifier for the [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) to get. The following table lists possible values for *dwAttrId*. These values are read-only. Note that vendors may not support all attributes.

| Value | Meaning |
| --- | --- |
| **SCARD_ATTR_ATR_STRING** | Answer to reset (ATR) string. |
| **SCARD_ATTR_CHANNEL_ID** | **DWORD** encoded as 0x*DDDDCCCC*, where *DDDD* = data channel type and *CCCC* = channel number: <br><br>* The following encodings are defined for *DDDD*:<br>* 0x01 serial I/O; *CCCC* is a port number.<br>* 0x02 parallel I/O; *CCCC* is a port number.<br>* 0x04 PS/2 keyboard port; *CCCC* is zero.<br>* 0x08 SCSI; *CCCC* is SCSI ID number.<br>* 0x10 IDE; *CCCC* is device number.<br>* 0x20 USB; *CCCC* is device number.<br>* 0xF*y* vendor-defined interface with *y* in the range zero through 15; *CCCC* is vendor defined. |
| **SCARD_ATTR_CHARACTERISTICS** | **DWORD** indicating which mechanical characteristics are supported. If zero, no special characteristics are supported. Note that multiple bits can be set: <br><br>* 0x00000001 Card swallowing mechanism<br>* 0x00000002 Card ejection mechanism<br>* 0x00000004 Card capture mechanism<br><br>All other values are reserved for future use (RFU). |
| **SCARD_ATTR_CURRENT_BWT** | Current block waiting time. |
| **SCARD_ATTR_CURRENT_CLK** | Current clock rate, in kHz. |
| **SCARD_ATTR_CURRENT_CWT** | Current character waiting time. |
| **SCARD_ATTR_CURRENT_D** | Bit rate conversion factor. |
| **SCARD_ATTR_CURRENT_EBC_ENCODING** | Current error block control encoding. <br><br>0 = longitudinal redundancy check (LRC)<br><br>1 = cyclical redundancy check (CRC) |
| **SCARD_ATTR_CURRENT_F** | Clock conversion factor. |
| **SCARD_ATTR_CURRENT_IFSC** | Current byte size for information field size card. |
| **SCARD_ATTR_CURRENT_IFSD** | Current byte size for information field size device. |
| **SCARD_ATTR_CURRENT_N** | Current guard time. |
| **SCARD_ATTR_CURRENT_PROTOCOL_TYPE** | **DWORD** encoded as 0x0*rrrpppp* where *rrr* is RFU and should be 0x000. *pppp* encodes the current protocol type. Whichever bit has been set indicates which ISO protocol is currently in use. (For example, if bit zero is set, [T=0 protocol](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) is in effect.) |
| **SCARD_ATTR_CURRENT_W** | Current work waiting time. |
| **SCARD_ATTR_DEFAULT_CLK** | Default clock rate, in kHz. |
| **SCARD_ATTR_DEFAULT_DATA_RATE** | Default data rate, in bps. |
| **SCARD_ATTR_DEVICE_FRIENDLY_NAME** | Reader's display name. |
| **SCARD_ATTR_DEVICE_IN_USE** | Reserved for future use. |
| **SCARD_ATTR_DEVICE_SYSTEM_NAME** | Reader's system name. |
| **SCARD_ATTR_DEVICE_UNIT** | Instance of this vendor's reader attached to the computer. The first instance will be device unit 0, the next will be unit 1 (if it is the same brand of reader) and so on. Two different brands of readers will both have zero for this value. |
| **SCARD_ATTR_ICC_INTERFACE_STATUS** | Single byte. Zero if [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) electrical contact is not active; nonzero if contact is active. |
| **SCARD_ATTR_ICC_PRESENCE** | Single byte indicating smart card presence: <br><br>0 = not present<br><br>1 = card present but not swallowed (applies only if reader supports smart card swallowing)<br><br>2 = card present (and swallowed if reader supports smart card swallowing)<br><br>4 = card confiscated. |
| **SCARD_ATTR_ICC_TYPE_PER_ATR** | Single byte indicating smart card type: <br><br>0 = unknown type<br><br>1 = 7816 Asynchronous<br><br>2 = 7816 Synchronous<br><br>Other values RFU. |
| **SCARD_ATTR_MAX_CLK** | Maximum clock rate, in kHz. |
| **SCARD_ATTR_MAX_DATA_RATE** | Maximum data rate, in bps. |
| **SCARD_ATTR_MAX_IFSD** | Maximum bytes for information file size device. |
| **SCARD_ATTR_POWER_MGMT_SUPPORT** | Zero if device does not support power down while smart card is inserted. Nonzero otherwise. |
| **SCARD_ATTR_PROTOCOL_TYPES** | **DWORD** encoded as 0x0*rrrpppp* where *rrr* is RFU and should be 0x000. *pppp* encodes the supported protocol types. A '1' in a given bit position indicates support for the associated ISO protocol, so if bits zero and one are set, both [T=0](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) and [T=1](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) protocols are supported. |
| **SCARD_ATTR_VENDOR_IFD_SERIAL_NO** | Vendor-supplied interface device serial number. |
| **SCARD_ATTR_VENDOR_IFD_TYPE** | Vendor-supplied interface device type (model designation of reader). |
| **SCARD_ATTR_VENDOR_IFD_VERSION** | Vendor-supplied interface device version (**DWORD** in the form 0x*MMmmbbbb* where *MM* = major version, *mm* = minor version, and *bbbb* = build number). |
| **SCARD_ATTR_VENDOR_NAME** | Vendor name. |

### `pbAttr` [out]

Pointer to a buffer that receives the attribute whose ID is supplied in *dwAttrId*. If this value is **NULL**, **SCardGetAttrib** ignores the buffer length supplied in *pcbAttrLen*, writes the length of the buffer that would have been returned if this parameter had not been **NULL** to *pcbAttrLen*, and returns a success code.

### `pcbAttrLen` [in, out]

Length of the *pbAttr* buffer in bytes, and receives the actual length of the received attribute If the buffer length is specified as SCARD_AUTOALLOCATE, then *pbAttr* is converted to a pointer to a byte pointer, and receives the address of a block of memory containing the attribute. This block of memory must be deallocated with
[SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory).

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Attribute value not supported.** | ERROR_NOT_SUPPORTED. |
| **Other Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

The **SCardGetAttrib** function is a direct card access function. For more information on other direct access functions, see
[Direct Card Access Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/direct-card-access-functions).

#### Examples

The following example shows how to retrieve an attribute for a card reader. The example assumes that hCardHandle is a valid handle obtained from a previous call to the [SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta) function.

```cpp
LPBYTE   pbAttr = NULL;
DWORD    cByte = SCARD_AUTOALLOCATE;
DWORD    i;
LONG     lReturn;

lReturn = SCardGetAttrib(hCardHandle,
                         SCARD_ATTR_VENDOR_NAME,
                         (LPBYTE)&pbAttr,
                         &cByte);
if ( SCARD_S_SUCCESS != lReturn )
{
    if ( ERROR_NOT_SUPPORTED == lReturn )
        printf("Value not supported\n");
    else
    {
        // Some other error occurred.
        printf("Failed SCardGetAttrib - %x\n", lReturn);
        exit(1);  // Or other appropriate action
    }
}
else
{
    // Output the bytes.
    for (i = 0; i < cByte; i++)
        printf("%c", *(pbAttr+i));
    printf("\n");

    // Free the memory when done.
    // hContext was set earlier by SCardEstablishContext
    lReturn = SCardFreeMemory( hContext, pbAttr );
}

```

## See also

[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta)

[SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory)

[SCardSetAttrib](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardsetattrib)