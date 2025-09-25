# IAzScope::get_PolicyReaders

## Description

The **PolicyReaders** property retrieves the [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs), in text form, of principals that act as policy readers.

This property is read-only.

## Parameters

## Remarks

Policy readers for an object can read attributes for the object and for child objects of the object. Readers can also use the policy; for example, readers can call the [AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck) method. Readers cannot modify the object or its child objects.

In JScript, the returned [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) must be converted to the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object.