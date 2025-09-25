# IRangeValueProvider::SetValue

## Description

Sets the value of the control.

## Parameters

### `val` [in]

Type: **double**

The value to set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The actual value set depends on the control implementation. The control may round the requested value up or down.

## See also

[IRangeValueProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irangevalueprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)