# ITextPara2::GetEffects

## Description

Gets the paragraph format effects.

## Parameters

### `pValue` [out]

Type: **long***

The paragraph effects. This value can be a combination of the following flags.

#### tomParaEffectRTL

#### tomParaEffectKeep

#### tomParaEffectKeepNext

#### tomParaEffectPageBreakBefore

#### tomParaEffectNoLineNumber

#### tomParaEffectNoWidowControl

#### tomParaEffectDoNotHyphen

#### tomParaEffectSideBySide

#### tomParaEffectCollapsed

#### tomParaEffectOutlineLevel

#### tomParaEffectBox

#### tomParaEffectTableRowDelimiter

#### tomParaEffectTable

### `pMask` [out]

Type: **long***

The differences in the flags over the range. A value of 1 indicates that the corresponding effect is the same over the range. For an insertion point, the values equal 1 for all defined effects.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the **tomTable** flag is set, you can use the [ITextRange2::GetTable](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-gettable) method to get more table properties.

## See also

[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)

[ITextPara2::SetEffects](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara2-seteffects)