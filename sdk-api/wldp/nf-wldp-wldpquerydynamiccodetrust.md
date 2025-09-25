## Description

Retrieves a value that determines if the specified in-memory or on-disk .NET CRL dynamic code is trusted by Device Guard policy.

## Parameters

### `fileHandle`

Handle to the on-disk dynamic code file to check. If *fileHandle* is non-**NULL**, *baseImage* should be **NULL**.

### `baseImage`

Pointer to the in-memory PE file to check. If *baseImage* is non-**NULL**, *FileHandle* should be **NULL**.

### `imageSize`

When *baseImage* is non-**NULL**, indicates the buffer size that *baseImage* points to.

## Return value

This method returns **S\_OK** if successful or a failure code otherwise.

## Remarks

## See also