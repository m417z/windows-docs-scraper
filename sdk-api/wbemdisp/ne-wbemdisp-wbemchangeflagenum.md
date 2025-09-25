# WbemChangeFlagEnum enumeration

## Description

The
WbemChangeFlagEnum constants define how a write operation to a class or an instance is carried out. A write operation is executed by [SWbemObject.Put_](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemobject-put-) or by [SWbemServicesEx.Put_](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemservicesex-put). These flags are used by
**SWbemObject.Put_** and
[SWbemObject.PutAsync_](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemobject-putasync-).

The WMI scripting type library, WbemDisp.tlb, defines these constants. Visual Basic applications can access this library; script languages must use the value of the constant directly, unless they use the Windows Script Host (WSH) XML file format. For more information, see
[Using the WMI Scripting Type Library](https://learn.microsoft.com/windows/desktop/WmiSdk/using-the-wmi-scripting-type-library).

## Constants

### `wbemChangeFlagCreateOrUpdate:0`

Causes the class or instance to be created, if it does not exist, or overwritten if it already exists.

### `wbemChangeFlagUpdateOnly:0x1`

Causes the call to update. The class or instance must exist for the call to be successful.

### `wbemChangeFlagCreateOnly:0x2`

Used for creation only. The call will fail if the class or instance already exists.

### `wbemChangeFlagUpdateCompatible:0`

Allows a class to be updated if there are no derived classes and there are no instances for that class. It also allows updates in all cases if the change is just to non-important qualifiers (for example, the [Description](https://learn.microsoft.com/windows/desktop/WmiSdk/standard-qualifiers) qualifier). If the class has instances, the update fails. This flag is used for compatibility with previous versions of WMI.

### `wbemChangeFlagUpdateSafeMode:0x20`

Allows updates of classes even if there are child classes as long as the change does not cause any conflicts with child classes. An example of an update this flag would allow would be to add a new property to the base class not previously mentioned in any of the child classes. If the class has instances, the update fails.

### `wbemChangeFlagUpdateForceMode:0x40`

Forces updates of classes when conflicting child classes exist.

An example of an update this flag forces would be if a class qualifier was defined in a child class, and the base class tried to add the same qualifier in conflict with the existing one. In the force mode, this conflict is resolved by deleting the qualifier in the child class. If the class has instances, the update fails.

Using the force mode to update a static class results in deletion of all instances of that class. Force update on provider classes does not delete instances of the class.

### `wbemChangeFlagStrongValidation:0x80`

**:** Notifies the operating system to return a failure on put operations to any invalid system instances. Examples of such instances are event-related instances, such as filters, bindings, or providers. By default, if these instances are invalid, the put operation reports success but an error is reported in the log.

### `wbemChangeFlagAdvisory:0x10000`

## See also

[Scripting API Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-constants)