# ITextRange2::Linearize

## Description

Translates the built-up math, ruby, and other inline objects in this range to linearized form.

## Parameters

### `Flags` [in]

Type: **long**

A combination of the following flags.

#### tomMathAlphabetics

#### tomMathBuildDownOutermost

#### tomMathBuildUpArgOrZone

#### tomMathRemoveOutermost

#### tomPlain

#### tomTeX

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

If the linearization is successful, the originally selected range is replaced by the linearized version.

If the **tomMathRemoveOutermost** or **tomMathBuildDownOutermost** build down mode is specified, the build down operation can be affected by the [tomMathChangeMask](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) values.

 The main purpose of these build-down modes is to facilitate transformations of the build-up math object as exposed by math context menus.

For example, to convert a stacked fraction to a linear fraction as in
(a+b/c)/(u+x/y)→((a+b/c))⁄((u+x/y)),
parentheses must be inserted; otherwise, you get a transformation
that looks incorrect, as in (a+b/c)/(u+x/y)→(a+b/c)⁄(u+x/y),
even though internally the linear fraction still has the original numerator and denominator.

The build-down process automatically inserts the parentheses, because the linear format for this case has parentheses, and the special change is made to replace the stacked-fraction operator U+002F by the linear fraction operator U+2215. Build up doesn't discard the parentheses for U+2215, but it does for U+002F.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)

[ITextRange2::BuildUpMath](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-buildupmath)