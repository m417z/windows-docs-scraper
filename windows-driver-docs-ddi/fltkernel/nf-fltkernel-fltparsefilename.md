# FltParseFileName function

## Description

**FltParseFileName** parses the extension, stream, and final component from a file name string.

## Parameters

### `FileName` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the string to parse as a file name. This parameter is required and cannot be **NULL**.

### `Extension` [in, out]

Pointer to a UNICODE_STRING structure that receives the extension parsed from the *FileName* string. If no extension is found, **FltParseFileName** sets *Extension.Buffer* to **NULL** and *Extension.Length* to zero. Otherwise, *Extension.Buffer* receives a pointer to the beginning of the extension in *FileName.Buffer*, and *Extension.Length* receives the length, in bytes, of the extension. This parameter is optional and can be **NULL**.

### `Stream` [in, out]

Pointer to a UNICODE_STRING structure that receives the stream name parsed from the *FileName* string. If no stream name is found, **FltParseFileName** sets *Stream.Buffer* to **NULL** and *Stream.Length* to zero. Otherwise, *Stream.Buffer* receives a pointer to the beginning of the stream name in *FileName.Buffer*, and *Stream.Length* receives the length, in bytes, of the stream name. This parameter is optional and can be **NULL**.

### `FinalComponent` [in, out]

Pointer to a UNICODE_STRING structure that receives the final name component parsed from the *FileName* string. If no final component is found, **FltParseFileName** sets *FinalComponent.Buffer* to **NULL** and *FinalComponent.Length* to zero. Otherwise, *FinalComponent.Buffer* receives a pointer to the beginning of the final component in *FileName.Buffer*, and *FinalComponent.Length* receives the length, in bytes, of the final component. This parameter is optional and can be **NULL**.

## Return value

**FltParseFileName** returns STATUS_SUCCESS or an appropriate NTSTATUS error code.

## Remarks

**FltParseFileName** parses the extension, stream name, and final component from a file name string. The file name is not required to be normalized or a full path name. If the file name is a short file name, **FltParseFileName** parses only the extension.

The following is an example of a normalized name for a local file:

```
\Device\HarddiskVolume1\Documents and Settings\MyUser\My Documents\Test Results.txt:stream1
```

**FltParseFileName** parses this normalized name as follows:

*Extension*: "txt"

*Stream*: ":stream1"

*FinalComponent*: "Test Results.txt:stream1"

The following is an example of a short name for a file:

```
TestRe~1.txt
```

**FltParseFileName** parses this short name as follows:

*Extension*: "txt"

*Stream*: **NULL**

*FinalComponent*: "TestRe~1.txt"

For more information about file name normalization and file name parsing, see [FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information).

To parse the contents of a FLT_FILE_NAME_INFORMATION structure, call [FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation).

## See also

[FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information)

[FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)