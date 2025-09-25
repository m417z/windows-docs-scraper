# LoadStringByReference function

## Description

Unsupported. **LoadStringByReference** may be altered or unavailable. Instead, use [SHLoadIndirectString](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shloadindirectstring).

## Parameters

### `Flags` [in]

Reserved.

### `Language` [in, optional]

The language.

### `SourceString` [in]

The source string reference.

### `Buffer` [out, optional]

The buffer to receive the string.

### `cchBuffer` [in]

The size of *Buffer*, in characters.

### `Directory` [in, optional]

The directory path to *SourceString*.

### `pcchBufferOut` [out, optional]

The number of characters written to *Buffer*.

## Return value

A **BOOL** datatype.

## Remarks

**LoadStringByReference** is not supported and may be altered or unavailable in the future. Instead, use [SHLoadIndirectString](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shloadindirectstring).