# ITMSPAddress::Initialize

## Description

The
**Initialize** method is called when the MSP is loaded.

## Parameters

### `hEvent` [in]

TAPI 3's handle for this MSP.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform operation. |

## Remarks

If an MSP is written using the MSP base classes, this method initializes data members, creates the Terminal Manager, and calls Start on the global MSP thread object.

## See also

[ITMSPAddress](https://learn.microsoft.com/windows/desktop/api/msp/nn-msp-itmspaddress)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)