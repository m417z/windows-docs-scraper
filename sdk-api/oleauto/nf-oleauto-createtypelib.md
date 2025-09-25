# CreateTypeLib function

## Description

Provides access to a new object instance that supports the [ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib) interface.

## Parameters

### `syskind`

The target operating system for which to create a type library.

### `szFile`

The name of the file to create.

### `ppctlib`

The [ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib) interface.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_IOERROR** | The function could not create the file. |

This method can also return the FACILITY_STORAGE errors.

## Remarks

**CreateTypeLib** sets its output parameter (ppctlib) to point to a newly created object that supports the [ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib) interface.

## See also

[Type Building Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/type-building-functions)