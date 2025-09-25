# IRDPSRAPISharingSession::GetDesktopSharedRect

## Description

Retrieves the current desktop region being shared.

## Parameters

### `pleft` [out]

Type: **long***

X-coordinate of the upper-left corner of the shared rectangle.

### `ptop` [out]

Type: **long***

Y-coordinate of the upper-left corner of the shared rectangle.

### `pright` [out]

Type: **long***

X-coordinate of the lower-right corner of the shared rectangle.

### `pbottom` [out]

Type: **long***

Y-coordinate of the lower-right corner of the shared rectangle.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPISharingSession](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapisharingsession)

[IRDPSRAPISharingSession2](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapisharingsession2)