# ITextRange::MoveWhile

## Description

Starts at a specified end of a range and searches while the characters belong to the set specified by *Cset* and while the number of characters is less than or equal to *Count*. The range is collapsed to an insertion point when a non-matching character is found.

## Parameters

### `Cset`

Type: **VARIANT***

The character set to use in the match. This could be an explicit string of characters or a character-set index. For more information, see [Character Match Sets](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model).

### `Count`

Type: **long**

Maximum number of characters to move past. The default value is **tomForward**, which searches to the end of the story. If *Count* is less than zero, the search starts at the start position and goes backward — toward the beginning of the story. If *Count* is greater than zero, the search starts at the end position and goes forward — toward the end of the story.

### `pDelta`

Type: **long***

The actual count of characters end is moved. This parameter can be null.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Cset is not valid. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

The motion described by [ITextRange::MoveUntil](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveuntil) is logical rather than geometric. That is, motion is toward the end or toward the start of a story. Depending on the language, moving to the end of the story could be moving left or moving right.

For more information, see the discussion in [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) and the Remarks section of [ITextRange::Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move).

The **ITextRange::MoveWhile** method is similar to [ITextRange::MoveUntil](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveuntil), but **MoveWhile** searches as long as it finds members of the set specified by *Cset*, and there is no additional increment to the value *pDelta*.

The [ITextRange::MoveStartWhile](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-movestartwhile) and [ITextRange::MoveEndWhile](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveendwhile) methods move the start and end, respectively, just past all contiguous characters that are found in set of characters specified by the *Cset* parameter.

The **VARIANT** type is primarily intended to be used with **IDispatch** scenarios like Microsoft Visual Basic for Applications (VBA), but it can be readily used from C or C++ as well. The following C++ code illustrates how to initialize and use the **VARIANT** argument for matching a span of digits in the range r.

```
VariantInit(&varg);
varg.vt = VT_I4;
varg.lVal = C1_DIGIT;
hr = r.MoveWhile(&varg, tomForward, pDelta); // Move IP past span of digits

```

Alternatively, an explicit string could be used, as in the following sample.

```
VariantInit(&varg);
bstr = SysAllocString("0123456789");
varg.vt = VT_BSTR;
varg.bstr = bstr;
hr =r.MoveWhile(&varg, tomForward, pDelta);    // Move IP past span of digits

```

The following VBA example code matches the body of the next Standard Generalized Markup Language (SGML) entry in a range, r. SGML entries start with <
`keyword ...`> and end with </
`keyword`>.

```
r.Find <                  // Get to start of next tag
r.MoveWhile C1_SPACE      // Bypass any space characters
r.MoveEndWhile C1_ALPHA   // Match keyword
s$ = </ + r               // Create VBA string to search for
r.Find >                  // Bypass remainder of start tag
r.FindEnd s$              // Match up to end of closing keyword
r.FindEnd <, tomStart     // Back up to start of end tag
                          // r has body of SGML entry

```

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[Move](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-move)

[MoveEndWhile](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveendwhile)

[MoveStartWhile](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-movestartwhile)

[MoveUntil](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-moveuntil)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)