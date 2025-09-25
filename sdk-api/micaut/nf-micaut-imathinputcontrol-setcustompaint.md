# IMathInputControl::SetCustomPaint

## Description

Determines whether a button or background has custom painting.

## Parameters

### `Element` [in]

The identifier for a button or background.

### `Paint` [in]

**VARIANT_TRUE** to enable custom painting for the specified UI element; otherwise, **VARIANT_FALSE**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If custom painting is enabled, the button or background will be rendered at least partially—and possibly completely—by the container.

## See also

[IMathInputControl](https://learn.microsoft.com/windows/desktop/api/micaut/nn-micaut-imathinputcontrol)