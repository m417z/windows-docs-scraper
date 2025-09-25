# SHSetInstanceExplorer function

## Description

Provides an interface that allows hosted Shell extensions and other components to prevent their host process from closing prematurely. The host process is typically Windows Explorer or Windows Internet Explorer, but this function can also be used by other applications.

## Parameters

### `punk` [in, optional]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to a free-threaded [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown). Components can use this interface (through [SHGetInstanceExplorer](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetinstanceexplorer)) to prevent the host process from terminating. This value can be **NULL**, in which case the process reference is no longer made available to components.

## Remarks

Windows Explorer and Internet Explorer can use **SHSetInstanceExplorer** to allow components such as Shell extensions to extend the lifetime of the process. Other applications can also use **SHSetInstanceExplorer** to allow for the same capability. For instance, the browser message loop and the proxy desktop use **SHSetInstanceExplorer** to let other threads extend their lifetime.

Applications other than Windows Explorer and Internet Explorer that call this function might encounter compatibility problems because some components use [SHGetInstanceExplorer](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetinstanceexplorer) to detect whether they are being hosted from within Windows Explorer or Internet Explorer.

The interface pointer passed to **SHSetInstanceExplorer** must reference a free-threaded object.

Each time a component calls [SHGetInstanceExplorer](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetinstanceexplorer), the system calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method before returning the interface pointer to the calling component. The component then calls the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method when processing is complete. The process that calls **SHSetInstanceExplorer** must not terminate while the reference count of the provided interface pointer is nonzero.

For further information on how components use the process references, see [SHGetInstanceExplorer](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetinstanceexplorer).

## See also

[SHGetInstanceExplorer](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetinstanceexplorer)