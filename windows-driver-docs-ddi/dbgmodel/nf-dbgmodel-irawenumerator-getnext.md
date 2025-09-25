# IRawEnumerator::GetNext

## Description

Moves the iterator forward and fetches the name of the raw element and, optionally, its value (or a reference to it) and what kind of element it is. Note that depending on how this enumerator was acquired, the object returned in the value field may be the value of the raw element (EnumerateRawValues) or a reference to the raw element (EnumerateRawReferences).
If there was an error in reading the value of the raw element (for EnumerateRawValues, for instance), the method may return an error *AND* fill value with an error object. When the enumerator hits the end of the sequence, E_BOUNDS will be returned.

## Parameters

### `name`

The name of the raw element (e.g.: field) being enumerated is returned here. The caller is responsible for freeing this string with the SysFreeString method.

### `kind`

The kind of symbol being enumerated (e.g.: a type, field, base class, etc…) is returned here.

### `value`

The value of the raw element (e.g.: field) being enumerated is optionally returned here. Depending on how the enumerator was acquired, this value may be the actual value of the raw element (EnumerateRawValues) or a reference to it (EnumerateRawReferences).

## Return value

This method returns HRESULT.

## Remarks

## See also

[IRawEnumerator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-irawenumerator)