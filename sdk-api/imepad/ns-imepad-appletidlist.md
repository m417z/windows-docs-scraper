# APPLETIDLIST structure

## Description

Specifies an [IImePadApplet](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepadapplet) IID list.

## Members

### `count`

The number of the IID's implemented in this applet.

### `pIIDList`

The IID list. This must be allocated with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc).