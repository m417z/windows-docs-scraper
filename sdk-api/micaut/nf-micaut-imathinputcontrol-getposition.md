# IMathInputControl::GetPosition

## Description

Retrieves the position and size of the control.

## Parameters

### `Left` [out]

The leftmost position of the control.

### `Top` [out]

The highest position of the control.

### `Right` [out]

The rightmost position of the control.

### `Bottom` [out]

The lowest position of the control.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns the control size and position even if the control is not visible.

This method returns the minimal possible width and height of the control if it is called immediately after creation of the control.

## See also

[IMathInputControl](https://learn.microsoft.com/windows/desktop/api/micaut/nn-micaut-imathinputcontrol)

[SetPosition](https://learn.microsoft.com/windows/desktop/api/micaut/nf-micaut-imathinputcontrol-setposition)