# SHGetRealIDL function

## Description

[**SHGetRealIDL** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Converts a simple pointer to an item identifier list (PIDL) into a full PIDL.

## Parameters

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to an instance of [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) whose simple PIDL is to be converted.

### `pidlSimple` [in]

Type: **PCUITEMID_CHILD**

The simple PIDL to be converted.

### `ppidlReal` [out]

Type: **PITEMID_CHILD***

When this method returns, contains a pointer to the full converted PIDL. If the function fails, this parameter is set to **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.