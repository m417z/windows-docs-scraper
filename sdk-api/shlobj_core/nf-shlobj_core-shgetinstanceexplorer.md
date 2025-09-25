# SHGetInstanceExplorer function

## Description

Retrieves an interface that allows hosted Shell extensions and other components to prevent their host process from closing prematurely. The host process is typically Windows Explorer or Windows Internet Explorer, but this function can also be used by other applications.

## Parameters

### `ppunk` [out]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

When this function returns successfully, contains the address of the host process' [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer. This is a free-threaded interface used to prevent the host process from terminating. If the function call fails, this value is set to **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

There are a number of components, such as Shell extension handlers, that are implemented as DLLs and run in a host process such as Windows Explorer (Explorer.exe) or Internet Explorer (Iexplore.exe). Typically, when the user closes the host process, the component is shut down immediately as well. Such an abrupt termination can create problems for some components. For example, if a component is using a background thread to download data or run user-interface functions, it might need additional time to safely shut itself down.

**SHGetInstanceExplorer** allows components that run in a host process to hold a reference on the host process. **SHGetInstanceExplorer** increments the host's reference count and returns a pointer to the host's [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. By holding that reference, a component can prevent the host process from closing prematurely. After the component has completed its necessary processing, it should call [(*ppunk)->Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release the host's reference and allow the process to terminate.

**Note** If **SHGetInstanceExplorer** is successful, the component must release the host's reference when it is no longer needed. Otherwise, all resources associated with the process will remain in memory. The [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointed to by **ppunk* can only be used to release this reference. Components cannot use [(*ppunk)->QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to request other interface pointers.

**SHGetInstanceExplorer** succeeds only if it is called from from an application which had previously called [SHSetInstanceExplorer](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shsetinstanceexplorer) to set a process reference.