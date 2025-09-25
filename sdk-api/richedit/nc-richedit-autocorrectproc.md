# AutoCorrectProc callback function

## Description

The *AutoCorrectProc* function is an
application-defined callback function that is used with the
[EM_SETAUTOCORRECTPROC](https://learn.microsoft.com/windows/desktop/Controls/em-setautocorrectproc) message.

*AutoCorrectProc* is a placeholder for the
application-defined function name. It provides application-defined automatic error correction for text entered
into a rich edit control.

## Parameters

### `langid`

Type: **[LANGID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Language ID that identifies the autocorrect file to use for automatic correcting.

### `pszBefore`

Type: **const [WCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Autocorrect candidate string.

### `pszAfter`

Type: **[WCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Resulting autocorrect string, if the return value is not **ATP_NOCHANGE**.

### `cchAfter`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Count of characters in *pszAfter*.

### `pcchReplaced`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Count of trailing characters in *pszBefore* to replace with *pszAfter*.

## Return value

Type: **int**

Returns one or more of the following values.

| Return code/value | Description |
| --- | --- |
| **ATP_NOCHANGE**<br><br>0 | No change. |
| **ATP_CHANGE**<br><br>1 | Change but don’t replace most delimiters, and don’t replace a span of unchanged trailing characters (preserves their formatting). |
| **ATP_NODELIMITER**<br><br>2 | Change but don’t replace a span of unchanged trailing characters. |
| **ATP_REPLACEALLTEXT**<br><br>4 | Replace trailing characters even if they are not changed (uses the same formatting for the entire replacement string). |

## See also

[EM_CALLAUTOCORRECTPROC](https://learn.microsoft.com/windows/desktop/Controls/em-callautocorrectproc)

[EM_GETAUTOCORRECTPROC](https://learn.microsoft.com/windows/desktop/Controls/em-getautocorrectproc)

[EM_SETAUTOCORRECTPROC](https://learn.microsoft.com/windows/desktop/Controls/em-setautocorrectproc)