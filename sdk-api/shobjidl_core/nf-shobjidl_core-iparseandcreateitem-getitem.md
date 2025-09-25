# IParseAndCreateItem::GetItem

## Description

Gets a stored Shell item that [SHCreateItemFromParsingName](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-shcreateitemfromparsingname) created from a parsing name.

## Parameters

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*, typically IID_IShellItem.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the interface pointer requested in *riid*. This is typically [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

We recommend that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.

## See also

[IParseAndCreateItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iparseandcreateitem)