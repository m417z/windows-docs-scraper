# CreateWriterEx function

## Description

This function is reserved for system use. Do not use this function directly. To create a VSS writer, extend the [CVssWriterEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriterex) class. The **CVssWriterEx** base class implicitly calls **CreateWriterEx**.

## Parameters

### `pWriter` [in]

Reserved.

### `pWriterImpl` [out]

Reserved.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CVssWriterEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriterex)