## Description

A callback function (implemented by your application), which is called by a DXCore object for notification events.

## Parameters

### `notificationType`

Type: **[DXCoreNotificationType](https://learn.microsoft.com/windows/win32/api/dxcore_interface/ne-dxcore_interface-dxcorenotificationtype)**

The type of notification representing this invocation. See the table in [DXCoreNotificationType](https://learn.microsoft.com/windows/win32/api/dxcore_interface/ne-dxcore_interface-dxcorenotificationtype) for info about what types are valid with which kinds of objects.

### `object`

Type: **[IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)\***

The [IDXCoreAdapter](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nn-dxcore_interface-idxcoreadapter) or [IDXCoreAdapterList](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nn-dxcore_interface-idxcoreadapterlist) object raising the notification.

### `context` [in]

Type: **void\***

A pointer, which may be `nullptr`, to an object containing context info.

## See also

[IDXCoreAdapter](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nn-dxcore_interface-idxcoreadapter), [IDXCoreAdapterList](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nn-dxcore_interface-idxcoreadapterlist), [DXCore reference](https://learn.microsoft.com/windows/win32/dxcore/dxcore-reference), [Using DXCore to enumerate adapters](https://learn.microsoft.com/windows/win32/dxcore/dxcore-enum-adapters)