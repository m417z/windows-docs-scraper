# IRichEditOleCallback::GetNewStorage

## Description

Provides storage for a new object pasted from the clipboard or read in from an Rich Text Format (RTF) stream.

## Parameters

### `lplpstg`

Type: **LPSTORAGE***

The address of the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface created for the new object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** on success. If the method fails, it can return one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | There was an invalid argument. |
| **E_OUTOFMEMORY** | There was not enough memory to do the operation. |

## Remarks

This method must be implemented to allow cut, copy, paste, drag, and drop operations of Component Object Model (COM) objects.

## See also

[IRichEditOleCallback](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditolecallback)

**Reference**