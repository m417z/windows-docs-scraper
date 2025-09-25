## Description

Instructs the object to initialize itself using the properties available in the property bag, and to notify the provided error log object when errors occur.

## Parameters

### `pPropBag`

The address of the caller's property bag, through which the object can read properties. This cannot be NULL.

### `pErrorLog`

The address of the caller's error log, in which the object stores any errors that occur during initialization. This can be NULL; in which case, the caller does not receive errors.

## Return value

## Remarks

All property loading must take place in the **IPersistPropertyBag::Load** function call, because the object cannot hold the IPropertyBag pointer.

E_NOTIMPL is not a valid return code, because any object that implements this interface must support the entire functionality of the interface.

## See also