# ICreateDeviceAccessAsync::GetResult

## Description

Retrieves an [IDeviceIoControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-ideviceiocontrol) object that's bound to the device interface that's specified in a call to the [CreateDeviceAccessInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nf-deviceaccess-createdeviceaccessinstance) function.

## Parameters

### `riid` [in]

An interface identifier that indicates what type of device access interface the caller wants to retrieve. The only valid value for this identifier is IID_IDeviceIoControl.

### `deviceAccess` [out]

If the binding was successful, contains an interface of the type that was supplied to the initial call to [CreateDeviceAccessInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nf-deviceaccess-createdeviceaccessinstance).

## Return value

This method supports standard return values, in addition to these:

| Return code | Description |
| --- | --- |
| **S_OK** | The binding was successful. |
| **E_ILLEGAL_METHOD_CALL** | The asynchronous operation wasn't in a valid state. The bind operation was either still in progress or not yet started. |

## See also

[ICreateDeviceAccessAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-icreatedeviceaccessasync)