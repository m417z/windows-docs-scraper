# ITextFont2::GetProperty

## Description

Gets the value of the specified property.

## Parameters

### `Type` [in]

Type: **long**

The property ID of the value to return.
See Remarks.

### `pValue` [out]

Type: **long***

The property value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Property IDs are defined by the Text Object Model (TOM). Here are how some of the TOM values are obtained:

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetProperty](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setproperty)