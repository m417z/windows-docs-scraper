# SCardSetAttrib function

## Description

The **SCardSetAttrib** function sets the given [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) attribute for the given handle. It does not affect the [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), [reader driver](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), or [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). Not all attributes are supported by all readers (nor can they be set at all times) as many of the attributes are under direct control of the transport protocol.

## Parameters

### `hCard` [in]

Reference value returned from
[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta).

### `dwAttrId` [in]

Identifier for the attribute to set. The values are write-only. Note that vendors may not support all attributes.

| Value | Meaning |
| --- | --- |
| **SCARD_ATTR_SUPRESS_T1_IFS_REQUEST** | Suppress sending of [T=1](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) IFSD packet from the reader to the card. (Can be used if the currently inserted card does not support an IFSD request.) |

### `pbAttr` [in]

Pointer to a buffer that supplies the attribute whose ID is supplied in *dwAttrId*.

### `cbAttrLen` [in]

Length (in bytes) of the attribute value in the *pbAttr* buffer.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

The **SCardSetAttrib** function is a direct card access function. For information about other direct access functions, see
[Direct Card Access Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/direct-card-access-functions).

#### Examples

The following example shows how to set an attribute.

```cpp
// Set the attribute.
// hCardHandle was set by a previous call to SCardConnect.
// dwAttrID is a DWORD value, specifying the attribute ID.
// pbAttr points to the buffer of the new value.
// cByte is the count of bytes in the buffer.
lReturn = SCardSetAttrib(hCardHandle,
                         dwAttrID,
                         (LPBYTE)pbAttr,
                         cByte);
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardSetAttrib\n");

```

## See also

[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta)

[SCardGetAttrib](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetattrib)