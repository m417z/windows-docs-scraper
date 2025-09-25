# SfcIsFileProtected function

## Description

Determines whether the specified file is protected. Applications should avoid replacing protected system files.

## Parameters

### `RpcHandle` [in]

This parameter must be **NULL**.

### `ProtFileName` [in]

The name of the file.

## Return value

If the file is protected, the return value is a nonzero value.

If the file is not protected, the return value is zero.

## See also

[SfcIsKeyProtected](https://learn.microsoft.com/windows/desktop/api/sfc/nf-sfc-sfciskeyprotected)