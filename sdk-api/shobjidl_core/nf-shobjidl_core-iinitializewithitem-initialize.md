# IInitializeWithItem::Initialize

## Description

Initializes a handler with an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

### `grfMode` [in]

Type: **DWORD**

One of the following [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) values that indicate the access mode for *psi*.

#### STGM_READ

The [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) is read-only.

#### STGM_READWRITE

The [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) is read/write accessible.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) cannot be accessed, this method returns an appropriate error code.

A handler instance should be initialized only once in its lifetime. Attempts by the calling application to reinitialize the handler result in the error `HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)`.