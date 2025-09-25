# AudioExtensionParams structure

## Description

This structure is passed to the Control Panel Endpoint Extension property page through [IShellPropSheetExt::AddPages](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellpropsheetext-addpages) and is used to create endpoint PropertyPages.

## Members

### `AddPageParam`

The add page param.

### `pEndpoint`

Pointer to the end point.

### `pPnpInterface`

Pointer to the Pnp interface.

### `pPnpDevnode`

Pointer to the Pnp devnode.

## See also

[Core Audio Structures](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-structures)

[IShellPropSheetExt::AddPages](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellpropsheetext-addpages)