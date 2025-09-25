# ITextRange2::BuildUpMath

## Description

Converts the linear-format math in a range to a built-up form, or modifies the current built-up form.

## Parameters

### `Flags` [in]

Type: **long**

A combination of the following flags.

#### tomChemicalFormula

#### tomHaveDelimiter

#### tomMathAlphabetics

#### tomMathApplyTemplate

#### tomMathArabicAlphabetics

#### tomMathAutoCorrect

#### tomMathAutoCorrectExt

#### tomMathAutoCorrectOpPairs

#### tomMathBackspace

#### tomMathBuildDown

#### tomMathBuildDownOutermost

#### tomMathBuildUpArgOrZone

#### tomMathBuildUpRecurse

#### tomMathChangeMask

#### tomMathCollapseSel

#### tomMathDeleteArg

#### tomMathDeleteArg1

#### tomMathDeleteArg2

#### tomMathDeleteCol

#### tomMathDeleteRow

#### tomMathEnter

#### tomMathInsColAfter

#### tomMathInsColBefore

#### tomMathInsRowAfter

#### tomMathInsRowBefore

#### tomMathMakeFracLinear

#### tomMathMakeFracSlashed

#### tomMathMakeFracStacked

#### tomMathMakeLeftSubSup

#### tomMathMakeSubSup

#### tomMathRemoveOutermost

#### tomMathRichEdit

#### tomMathShiftTab

#### tomMathSingleChar

#### tomMathSubscript

#### tomMathSuperscript

#### tomMathTab

#### tomNeedTermOp

#### tomPlain

#### tomShowEmptyArgPlaceholders

#### tomTeX

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the **ITextRange2::BuildUpMath** method is called on a nondegenerate range, the method checks the text for math italic conversions (if **tomMathAlphabetics** is specified) and math autocorrect conversions (if **tomMathAutoCorrect** or **tomMathAutoCorrectExt** is specified). Then, the method attempts to build up the selected text. If successful, the method replaces the previous text in the range with the built-up text. If the method makes any changes to the range, the function returns **NOERROR** and the range selects the result. If the method does change the range, it returns **S_FALSE** or a Component Object Model (COM) error code.

If the **ITextRange2::BuildUpMath** method is called on a degenerate range, the **BuildUpMath** method treats the range as an insertion point (IP) immediately following the last character input. The method converts that character, possibly along with some preceding characters, to math italic (if **tomMathAlphabetics** is specified), internal math autocorrect (if **tomMathAutoCorrect** is specified), negated operators, and some operator pairs (if **tomMathAutoCorrectOpPairs** is specified). If the IP is inside an argument, the method scans a range of text from the IP back to the start of a math object argument; otherwise, the method scans to the start of the current math zone. The scan is terminated by a hard carriage return or a soft end-of-paragraph mark, because math zones are terminated by these marks. A scan forward from start of the math object argument or math zone bypasses text that has no chance of being built up. If the scan reaches the original entry IP, one of the following outcomes can occur:

* If the method made any changes, the function returns **NOERROR** and the range updated with the changed text.
* If the method made no changes, the function returns **S_FALSE** and leaves the range unchanged.

If the scan finds text that might get built up, the **BuildUpMath** method attempts to build up the text up to the insertion point. If successful, the method returns **NOERROR**, and the range is updated with the corresponding built-up text.

If this full build-up attempt fails, the **BuildUpMath** method does a partial build-up check for the expression immediately preceding the IP. If this succeeds, the method returns **NOERROR** and the range contains the linear text to be replaced by the built-up text.

If full and partial build-up attempts fail, the function returns as described previously for the cases where no build-up text was found. Other possible return values include **E_INVALIDARG** (if either interface pointer is **NULL**) and **E_OUTOFMEMORY**.

You should set the **tomNeedTermOp** flag should for formula autobuildup unless autocorrection has occurred that deletes the terminating blank. Autocorrection can occur when correcting text like \alpha when the user types a blank to force autocorrection.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)

[ITextRange2::Linearize](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-linearize)