# ITextPara2::GetProperty

## Description

Gets the value of the specified property.

## Parameters

### `Type` [in]

Type: **long**

The ID of the property value to retrieve.

### `pValue` [out]

Type: **long***

The property value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [tomParaPropMathAlign](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) property sets the math alignment for math paragraphs in a text paragraph. It can have one of the following values.

[tomMathParaAlignDefault](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomMathParaAlignCenterGroup](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomMathParaAlignCenter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomMathParaAlignLeft](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomMathParaAlignRight](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

## See also

[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)

[ITextPara2::SetProperty](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara2-setproperty)