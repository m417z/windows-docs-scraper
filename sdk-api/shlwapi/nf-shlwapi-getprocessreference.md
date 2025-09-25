# GetProcessReference function

## Description

Retrieves the process-specific object supplied by [SetProcessReference](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-setprocessreference), incrementing the reference count to keep the process alive.

## Parameters

### `punk` [out]

The address of a pointer that, when this function returns successfully, points to the object supplied to the process by [SetProcessReference](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-setprocessreference). Your application is responsible for freeing this resource when it is no longer needed.

A pointer to a free-threaded [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown). Components can use this interface (through [SHGetInstanceExplorer](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetinstanceexplorer)) to prevent the host process from terminating. This value can be **NULL**, in which case the process reference is no longer made available to components.

## Remarks

There are a number of components, such as Shell extension handlers, that are implemented as DLLs and run in a host process such as Windows Explorer (Explorer.exe) or Windows Internet Explorer (Iexplore.exe). Typically, when the user closes the host process, the component is shut down immediately as well. Such an abrupt termination can create problems for some components. For example, if a component is using a background thread to download data or run user-interface functions, it might need additional time to safely shut itself down.

**GetProcessReference** allows components that run in a host process to hold a reference on the host process. **GetProcessReference** increments the host's reference count and returns a pointer to the host's [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. By holding that reference, a component can prevent the host process from closing prematurely. After the component has completed its necessary processing, it should call [(*punk)->Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release the host's reference and allow the process to terminate.

**Note** If **GetProcessReference** is successful, the component must release the host's reference when it is no longer needed. Otherwise, all resources associated with the process will remain in memory. The [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointed to by **punk* can only be used to release this reference. Components cannot use [(*punk)->QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to request other interface pointers.

**GetProcessReference** succeeds only if it is called from an application which had previously called [SetProcessReference](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-setprocessreference) to set a process reference.

## See also

[SHGetInstanceExplorer](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetinstanceexplorer)

[SetProcessReference](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-setprocessreference)

[Windows API Sets](https://learn.microsoft.com/windows/desktop/apiindex/windows-apisets)