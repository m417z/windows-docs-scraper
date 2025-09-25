# IMathInputControl::SetPosition

## Description

Modifies the location and size of the control.

## Parameters

### `Left` [in]

The leftmost position of the control.

### `Top` [in]

The highest position of the control.

### `Right` [in]

The rightmost position of the control.

### `Bottom` [in]

The lowest position of the control.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The control was resized but the resulting width, height, or both are not equal to the input parameters. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method can be called regardless of the control visibility state.

This method will succeed even if parameters are not valid. If the rectangle is larger than the maximum allowed size of the control (desktop window), the maximum possible size is used instead. If the rectangle is smaller than the minimal size of the control, or too small to keep the ink and result preview intact, the minimal possible size is used instead.

If the method returns **S_FALSE**, the [GetPosition](https://learn.microsoft.com/windows/desktop/api/micaut/nf-micaut-imathinputcontrol-getposition) method will return the actual size characteristics of the control.

## See also

[GetPosition](https://learn.microsoft.com/windows/desktop/api/micaut/nf-micaut-imathinputcontrol-getposition)

[IMathInputControl](https://learn.microsoft.com/windows/desktop/api/micaut/nn-micaut-imathinputcontrol)