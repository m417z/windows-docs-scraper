# IAzScope::get_PolicyAdministrators

## Description

The **PolicyAdministrators** property retrieves the [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs), in text form, of principals that act as policy administrators.

This property is read-only.

## Parameters

## Remarks

Policy administrators for an object can perform the following tasks:

* Read the object
* Write attributes to the object
* Read attributes of child objects of the object
* Write attributes to child objects of the object
* Delete the object
* Delete child objects of the object
* Create child objects of the object

In JScript, the returned [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) must be converted to the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object.