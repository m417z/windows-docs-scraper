# IBrowserService2::_ResizeNextBorder

## Description

Deprecated. Resizes the border of the browser view in response to the addition or removal of toolbars.

## Parameters

### `itb` [in]

Type: **UINT**

The index of the toolbar that was added or removed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The implementation of this method calls [IBrowserService2::_ResizeNextBorderHelper](https://learn.microsoft.com/windows/win32/api/shdeprecated/nf-shdeprecated-ibrowserservice2-_resizenextborderhelper).