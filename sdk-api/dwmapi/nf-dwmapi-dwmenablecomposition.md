# DwmEnableComposition function

## Description

Enables or disables Desktop Window Manager (DWM) composition.

**Note** This function is deprecated as of Windows 8. DWM can no longer be programmatically disabled.

## Parameters

### `uCompositionAction` [in]

**DWM_EC_ENABLECOMPOSITION** to enable DWM composition; **DWM_EC_DISABLECOMPOSITION** to disable composition.

**Note** As of Windows 8, calling this function with **DWM_EC_DISABLECOMPOSITION** has no effect. However, the function will still return a success code.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Disabling DWM composition disables it for the entire desktop. DWM composition will be automatically enabled when all processes that have disabled composition have called **DwmEnableComposition** to enable it or have been terminated. The [WM_DWMCOMPOSITIONCHANGED](https://learn.microsoft.com/windows/desktop/dwm/wm-dwmcompositionchanged) notification is sent whenever DWM composition is enabled or disabled.

#### Examples

The following code example disables DWM composition.

```cpp

...
HRESULT hr = S_OK;

// Disable DWM Composition
hr = DwmEnableComposition(DWM_EC_DISABLECOMPOSITION);
if (SUCCEEDED(hr))
{
   // ...
}
...
```

## See also

[Enable and Control DWM Composition](https://learn.microsoft.com/windows/desktop/dwm/composition-ovw)