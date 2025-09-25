# SL_NONGENUINE_UI_OPTIONS structure

## Description

Specifies an application that displays a dialog box when the [SLIsGenuineLocal](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slisgenuinelocal) function indicates that an installation is not genuine.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `pComponentId`

A pointer to an **SLID** structure that specifies an application that displays a dialog box.

### `hResultUI`

The return value that the [SLIsGenuineLocal](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slisgenuinelocal) function returns when an installation is not genuine.