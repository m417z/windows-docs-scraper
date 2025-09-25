## Description

Instructs the object to save its properties to the given property bag, and optionally, to clear the object's dirty flag.

## Parameters

### `pPropBag`

The address of the caller's property bag, through which the object can write properties. This cannot be NULL.

### `fClearDirty`

A flag indicating whether the object should clear its dirty flag when the "Save" operation is complete. TRUE means clear the flag, and FALSE means leave the flag unaffected. FALSE is used when the caller performs a "Save Copy As" operation.

### `fSaveAllProperties`

A flag indicating whether the object should save all its properties (TRUE), or save only those properties that have changed from the default value (FALSE).

## Return value

## Remarks

The caller can request that the object save all properties, or save only those properties that have changed.

E_NOTIMPL is not a valid return code, because any object that implements this interface must support the entire functionality of the interface.

## See also