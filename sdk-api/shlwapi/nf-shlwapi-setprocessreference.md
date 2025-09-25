# SetProcessReference function

## Description

Provides a Component Object Model (COM) object that allows hosted Shell extensions and other components to prevent their host process from closing prematurely. The host process is typically Windows Explorer or Windows Internet Explorer, but this function can also be used by other applications.

## Parameters

### `punk` [in, optional]

A pointer to the object for which you want to store a reference. This value can be **NULL**.

## Remarks

Windows Explorer and Internet Explorer can use **SetProcessReference** to allow components such as Shell extensions to extend the lifetime of the process. Other applications can also use **SetProcessReference** to allow for the same capability. For instance, the browser message loop and the proxy desktop use **SetProcessReference** to let other threads extend their lifetime.

Applications other than Windows Explorer and Internet Explorer that call this function might encounter compatibility problems because some components use **SetProcessReference** to detect whether they are being hosted from within Windows Explorer or Internet Explorer.

The interface pointer passed to **SetProcessReference** must reference a free-threaded object.

Each time a component calls [GetProcessReference](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-getprocessreference), the system calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method before returning the interface pointer to the calling component. The component then calls the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method when processing is complete. The process that calls **SetProcessReference** must not terminate while the reference count of the provided interface pointer is nonzero.

For further information on how components use the process references, see [GetProcessReference](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-getprocessreference).

## See also

[GetProcessReference](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-getprocessreference)

[SHSetInstanceExplorer](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shsetinstanceexplorer)

[Windows API Sets](https://learn.microsoft.com/windows/desktop/apiindex/windows-apisets)