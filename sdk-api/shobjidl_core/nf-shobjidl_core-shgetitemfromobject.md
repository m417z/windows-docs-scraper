# SHGetItemFromObject function

## Description

Retrieves an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) for an object.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the object.

### `riid` [in]

Type: **REFIID**

Reference to the desired IID.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or a related interface.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

From the standpoint of performance, this method is preferred to [SHGetIDListFromObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shgetidlistfromobject) in those cases where the IDList is already bound to a folder.

## See also

[SHCreateItemFromIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateitemfromidlist)

[SHGetIDListFromObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shgetidlistfromobject)