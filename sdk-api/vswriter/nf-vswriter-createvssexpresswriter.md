# CreateVssExpressWriter function

## Description

Creates an [IVssExpressWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivssexpresswriter) interface object and returns a pointer to it.

**Note** This function is exported as **CreateVssExpressWriterInternal**, but you should call **CreateVssExpressWriter**, not **CreateVssExpressWriterInternal**.

## Parameters

### `ppWriter` [out]

Doubly indirect pointer to the newly created [IVssExpressWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivssexpresswriter) object.

## Return value

The return values listed here are in addition to the normal COM HRESULT values that may be returned at any time from the function.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an [IVssExpressWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivssexpresswriter) interface. |
| **E_ACCESSDENIED** | The caller does not have sufficient privileges. |
| **E_INVALIDARG** | One of the parameters is not valid. |