## Description

Creates an NT handle for controlling access to scanout on this path. A compositor application can choose to broker access to paths that it controls using these objects. Your application can call [IDisplayDeviceInterop.OpenSharedHandle](https://learn.microsoft.com/windows/win32/api/windows.devices.display.core.interop/nf-windows-devices-display-core-interop-idisplaydeviceinterop-opensharedhandle) to create a [DisplaySource](https://learn.microsoft.com/uwp/api/windows.devices.display.core.displaysource) object from this handle.

## Parameters

### `pValue`

Type: **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to a **HANDLE** that receives the newly created source presentation object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **S_OK** if it succeeded, otherwise a failure code indicating why it failed. If it succeeded, then *pValue* will always point to the newly created handle.

## Remarks

Multiple processes can have handles of the same object, enabling use of the object for interprocess synchronization or sharing. These object-sharing mechanisms are available.

* A process can specify the object handle in a call to the [DuplicateHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-duplicatehandle) function to create a duplicate handle that can be used by another process.
* A process can specify the name of the object in a call to the [IDisplayDeviceInterop.OpenSharedHandle](https://learn.microsoft.com/windows/win32/api/windows.devices.display.core.interop/nf-windows-devices-display-core-interop-idisplaydeviceinterop-opensharedhandle) function.

Use the [CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) function to close the handle. The system closes the handle automatically when the process terminates. The object is destroyed when its last handle has been closed and its last interface reference has been released.

## See also