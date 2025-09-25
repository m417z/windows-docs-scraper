# WsTrimXmlWhitespace function

## Description

Removes leading and trailing whitespace from a sequence of characters.

## Parameters

### `chars`

The string to be trimmed.

### `charCount` [in]

The length of the string to be trimmed.

### `trimmedChars`

Returns a pointer into the original string starting at the first non-whitespace character.

### `trimmedCount` [out]

Returns the length of the trimmed string.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The function returns a pointer into the original string. The original string passed in is not modified.

XML defines whitespace as characters 9 (0x9), 10 (0xA), 13 (0xD), and 32 (0x20).