# ITMSPAddress::GetEvent

## Description

The
**GetEvent** method retrieves event information.

## Parameters

### `pdwSize` [in, out]

A pointer to a DWORD that contains the size, in bytes, of *pEventBuffer*. On success, *pdwSize* returns the actual number of bytes in *pEventBuffer*. If *pEventBuffer* is not large enough, the method returns **TAPI_E_NOTENOUGHMEMORY** and
this parameter returns the number, in bytes, required.

### `pEventBuffer`

[in, out, size_is(**pdwSize*)] A pointer to buffer that contains
[MSP event_info](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info) information.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_NOTIMPL** | Method not implemented. |
| **E_POINTER** | The *pdwSize* or *pEventBuffer* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_NOTENOUGHMEMORY** | The *pdwSize* parameter was not large enough for the buffer. |
| **TAPI_E_NOEVENT** | No event has occurred. |

## Remarks

TAPI3 calls this method when the event handle given in initialize is signaled. TAPI will call this method repeatedly until it fails so it can get multiple events. Each call should return only one event structure.

Users of the MSP base classes: This method locks the event list.

## See also

[ITMSPAddress](https://learn.microsoft.com/windows/desktop/api/msp/nn-msp-itmspaddress)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)