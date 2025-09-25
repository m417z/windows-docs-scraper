## Description

The **RtlInitEmptyUnicodeString** macro initializes an empty counted Unicode string.

## Parameters

### `UnicodeString` [out]

Pointer to the [**UNICODE_STRING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfwdm/ns-wudfwdm-_unicode_string) structure to be initialized.

### `Buffer` [in]

Pointer to a caller-allocated buffer to be used to contain a WCHAR string.

### `BufferSize` [in]

Length, in bytes, of the buffer that _Buffer_ points to.

## Remarks

The members of the structure that the _DestinationString_ parameters points to are initialized as follows.

* **Length**. Zero.

* **MaximumLength**. _BufferSize_.

* **Buffer**. _SourceString_.

To initialize a non-empty counted Unicode string, call [**RtlInitUnicodeString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring).