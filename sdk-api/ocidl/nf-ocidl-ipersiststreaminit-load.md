# IPersistStreamInit::Load

## Description

Initializes an object from the stream where it was saved previously.

## Parameters

### `pStm` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer to the stream from which the object should be loaded.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_OUTOFMEMORY** | The object was not loaded due to lack of memory. |
| **E_FAIL** | The object was not loaded due to some reason other than a lack of memory. |

## Remarks

If the object has already been initialized with [IPersistStreamInit::InitNew](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipersiststreaminit-initnew), then this method must return E_UNEXPECTED.

This method loads an object from its associated stream. The seek pointer is set as it was in the most recent [IPersistStreamInit::Save](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipersiststreaminit-save) method. This method can seek and read from the stream, but cannot write to it.

## See also

[IPersistStreamInit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipersiststreaminit)