## Description

The **RtlInitEmptyAnsiString** macro initializes an empty counted ANSI string.

## Parameters

### `AnsiString` [out]

Pointer to the [**ANSI_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string) structure to be initialized.

### `Buffer` [in]

Pointer to a caller-allocated buffer to be used to contain an ANSI string composed of CHAR elements.

### `BufferSize` [in]

Length, in bytes, of the buffer that _Buffer_ points to.

## Remarks

The members of the structure that the _DestinationString_ parameter points to are initialized as follows.

* **Length**. Zero.

* **MaximumLength**. _BufferSize_.

* **Buffer**. _SourceString_.

To initialize a non-empty counted ANSI string, call [**RtlInitAnsiString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitansistring).