# TTRunValidationTestsEx function

## Description

Validates part or all glyph data of a UCS-4 character (32-bit) font, in the size range specified.

**Windows Vista and later**: this function will always return E_API_NOTIMPL, and no processing is performed by this API.

## Parameters

### `hDC` [in]

Device context handle.

### `pTestParam` [in]

Pointer to a [TTVALIDATIONTESTPARAMSEX](https://learn.microsoft.com/windows/desktop/api/t2embapi/ns-t2embapi-ttvalidationtestsparamsex) structure specifying the parameters to test.

## Return value

If successful and the glyph data is valid, returns E_NONE.

Otherwise, returns an error code described in [Embedding-Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-embedding-function-error-messages).

## Remarks

**TTRunValidationTestsEx** is a UCS-4 version of [TTRunValidationTests](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttrunvalidationtests).

This function was supported in Windows XP and earlier, but is no longer supported. In Windows Vista and later, this function will always return E_API_NOTIMPL, and no processing is performed by this API.

Effective font validation can be performed by a tool, such as Font Validator, that is capable of performing thorough validation of all parts of the font file. Please see \<https://www.microsoft.com/typography/FontValidator.aspx> for information on the Font Validator tool.

## See also

[TTRunValidationTests](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttrunvalidationtests)

[TTVALIDATIONTESTPARAMSEX](https://learn.microsoft.com/windows/desktop/api/t2embapi/ns-t2embapi-ttvalidationtestsparamsex)