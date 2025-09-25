# IAgileReference::Resolve(Q,)

## Description

Gets the interface ID of an agile reference to an object.

## Parameters

### `pp` [in]

The interface ID of the interface to be retrieved from the agile reference. It is not required to be the same as the registered interface.

### `unnamedParam2` [out, retval]

On successful completion, **ppvObjectReference* is a pointer to the interface specified by *riid*.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method completed successfully. |
| E_NOINTERFACE | The requested interface isn't implemented on the registered object. |

## Remarks

Call the [RoGetAgileReference](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-rogetagilereference) function to create an agile reference to an object. Call the **Resolve** method to localize the object into the apartment in which **Resolve** is called.

## See also

[IAgileReference](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iagilereference)

[RoGetAgileReference](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-rogetagilereference)

