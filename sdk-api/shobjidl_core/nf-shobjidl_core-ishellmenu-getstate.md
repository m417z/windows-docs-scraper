# IShellMenu::GetState

## Description

Gets a filled [SMDATA](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-smdata) structure.

## Parameters

### `psmd` [out]

Type: **LPSMDATA**

When this method returns, contains a pointer to an [SMDATA](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-smdata) structure that contains information about the menu band.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.