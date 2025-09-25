# WbemQueryFlagEnum enumeration

## Description

The
**WbemQueryFlagEnum** constants define the depth of enumeration or query, which determines how many objects are returned by a call. These constants are used by
[SWbemServices.SubclassesOf](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemservices-subclassesof),
[SWbemServices.InstancesOf](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemservices-instancesof),
[SWbemObject.Subclasses_](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemobject-subclasses-), and
[SWbemObject.Instances_](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemobject-instances-).

The WMI scripting type library, wbemdisp.tlb, defines these constants. Visual Basic applications can access this library; script languages must use the value of the constant directly, unless they use Windows Script Host (WSH) XML file format. For more information, see
[Using the WMI Scripting Type Library](https://learn.microsoft.com/windows/desktop/WmiSdk/using-the-wmi-scripting-type-library).

## Constants

### `wbemQueryFlagDeep:0`

Forces recursive enumeration into all subclasses derived from the specified parent class. The parent class itself is not returned in the enumeration.

### `wbemQueryFlagShallow:1`

Forces the enumeration to include only immediate subclasses of the specified parent class.

### `wbemQueryFlagPrototype:2`

Used for prototyping. It stops the query from happening and instead returns an object that look like a typical result object.

## See also

[Scripting API Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-constants)