# ITMSPAddress::Shutdown

## Description

The
**Shutdown** method is called when the MSP is unloaded.
**Shutdown** will be called once per address object.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_NOTIMPL** | Method not implemented. |

## Remarks

This method releases the terminals and releases the Terminal Manager. It releases all unprocessed events, and calls
[Stop](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itmediacontrol-stop) on the global MSP thread object. When this function is called, no call should be alive. However, bugs in the application may keep calls or terminals around.

## See also

[ITMSPAddress](https://learn.microsoft.com/windows/desktop/api/msp/nn-msp-itmspaddress)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)