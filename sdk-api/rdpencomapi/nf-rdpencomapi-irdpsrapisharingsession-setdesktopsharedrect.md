# IRDPSRAPISharingSession::SetDesktopSharedRect

## Description

Sets the desktop region that will be shared.

## Parameters

### `left` [in]

Type: **long**

X-coordinate of the upper-left corner of the shared rectangle.

### `top` [in]

Type: **long**

Y-coordinate of the upper-left corner of the shared rectangle.

### `right` [in]

Type: **long**

X-coordinate of the lower-right corner of the shared rectangle.

### `bottom` [in]

Type: **long**

Y-coordinate of the lower-right corner of the shared rectangle.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPISharingSession](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapisharingsession)

[IRDPSRAPISharingSession2](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapisharingsession2)