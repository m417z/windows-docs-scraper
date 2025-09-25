# LresultFromObject function

## Description

Returns a reference, similar to a handle, to the specified object. Servers return this reference when handling [WM_GETOBJECT](https://learn.microsoft.com/windows/desktop/WinAuto/wm-getobject).

## Parameters

### `riid` [in]

Type: **REFIID**

Reference identifier of the interface provided to the client. This parameter is IID_IAccessible.

### `wParam` [in]

Type: **[WPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value sent by the associated [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message in its *wParam* parameter.

### `punk` [in]

Type: **LPUNKNOWN**

Address of the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface to the object that corresponds to the [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message.

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns a positive value that is a reference to the object.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_NOINTERFACE** | The object specified in the *pAcc* parameter does not support the interface specified in the *riid* parameter. |
| **E_OUTOFMEMORY** | Insufficient memory to store the object reference. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

Servers call this function only when handling the [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message. For an overview of how **LresultFromObject** is related to **WM_GETOBJECT**, see [How WM_GETOBJECT Works](https://learn.microsoft.com/windows/desktop/WinAuto/how-wm-getobject-works).

**LresultFromObject** increments the object's reference count. If you are not storing the interface pointer passed to the function (that is, you create a new interface pointer for the object each time [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) is received), call the object's [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method to decrement the reference count back to one. Then the client calls **Release** and the object is destroyed. For more information, see [How to Handle WM_GETOBJECT](https://learn.microsoft.com/windows/desktop/WinAuto/how-to-handle-wm-getobject).

Each time a server processes [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) for a specific object, it calls **LresultFromObject** to obtain a new reference to the object. Servers do not save the reference returned from **LresultFromObject** from one instance of processing **WM_GETOBJECT** to use as the message's return value when processing subsequent **WM_GETOBJECT** messages for the same object. This causes the client to receive an error.

## See also

[Creating Proxy Objects](https://learn.microsoft.com/windows/desktop/WinAuto/creating-proxy-objects)

[How WM_GETOBJECT Works](https://learn.microsoft.com/windows/desktop/WinAuto/how-wm-getobject-works)

[How to Handle WM_GETOBJECT](https://learn.microsoft.com/windows/desktop/WinAuto/how-to-handle-wm-getobject)

[WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject)