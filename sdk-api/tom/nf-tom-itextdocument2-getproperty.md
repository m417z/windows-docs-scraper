# ITextDocument2::GetProperty

## Description

Retrieves the value of a property.

## Parameters

### `Type` [in]

Type: **long**

The identifier of the property to retrieve. It can be one of the following property IDs.

#### tomCanCopy

#### tomCanRedo

#### tomCanUndo

#### tomDocMathBuild

#### tomMathInterSpace

#### tomMathIntraSpace

#### tomMathLMargin

#### tomMathPostSpace

#### tomMathPreSpace

#### tomMathRMargin

#### tomMathWrapIndent

#### tomMathWrapRight

#### tomUndoLimit

#### tomEllipsisMode

#### tomEllipsisState

### `pValue` [out]

Type: **long***

The value of the property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

[ITextDocument2::GetMathProperties](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-getmathproperties)

[ITextDocument2::SetProperty](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-setproperty)