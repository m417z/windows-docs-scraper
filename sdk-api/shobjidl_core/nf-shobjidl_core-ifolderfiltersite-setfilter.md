# IFolderFilterSite::SetFilter

## Description

Exposed by a host to allow clients to pass the host their [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointers.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the client's [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. To notify the host to terminate filtering and stop calling your [IFolderFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderfilter) interface, set this parameter to **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After you get a pointer to the host's [IFolderFilterSite](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderfiltersite) interface, call this method to pass the host a pointer to your [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. The host will then use this pointer to call your [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method to request a pointer to your [IFolderFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderfilter) interface. If this call fails, **IFolderFilterSite::SetFilter** returns **E_NOINTERFACEAVAILABLE**. If the call is successful, the host will then call the **IFolderFilter** interface's two methods to determine how to enumerate the contents of the folder.