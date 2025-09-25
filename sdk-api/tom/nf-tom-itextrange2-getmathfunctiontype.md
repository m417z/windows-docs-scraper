# ITextRange2::GetMathFunctionType

## Description

Retrieves the math function type associated with the specified math function name.

## Parameters

### `bstr` [in]

Type: **BSTR**

The math function name that is checked to determine the math function type.

### `pValue` [out]

Type: **long***

The math function type of the function name specified by *bstr*. It can be one of the following values.

#### tomFunctionTypeNone

#### tomFunctionTypeTakesArg

#### tomFunctionTypeTakesLim

#### tomFunctionTypeTakesLim2

#### tomFunctionTypeIsLim

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)