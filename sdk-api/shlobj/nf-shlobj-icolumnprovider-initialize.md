# IColumnProvider::Initialize

## Description

Initializes an [IColumnProvider](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-icolumnprovider) interface.

## Parameters

### `psci` [in]

Type: **LPCSHCOLUMNINIT**

An [SHCOLUMNINIT](https://learn.microsoft.com/windows/desktop/api/shlobj/ns-shlobj-shcolumninit) structure with initialization information, including the folder whose contents are to be displayed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.