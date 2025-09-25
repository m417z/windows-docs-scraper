# IRoSimpleMetaDataBuilder structure

## Description

Provides a metadata locator with a destination for the metadata it has discovered.

This member supports the Windows Runtime infrastructure and is not intended to be used directly from your code.

## Members

### `SetWinRtInterface`

Assigns a Windows Runtime interface to the metadata builder.

[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable) and other non-Windows Runtime interfaces are not allowed. Not for use with parameterized type instances.

#### iid

The IID for the interface.

### `SetDelegate`

Assigns a delegate to the metadata builder.

#### iid

COM interface IID for the specified delegate type.

### `SetInterfaceGroupSimpleDefault`

Assigns an interface group to the metadata builder.

#### name

The fully qualified name of the specified interface group type.

#### defaultInterfaceName

The fully qualified name of the default interface (must be a non-parametric type).

#### defaultInterfaceIID

Optional.
If null, a separate call will be made to resolve the default interface type.
If not null, pointer to a GUID that contains the IID for the default interface named by *defaultInterfaceName*.

### `SetInterfaceGroupParameterizedDefault`

Assigns an interface group with a parameterized interface as the default interface to the metadata builder.

Call this method when an interface group has a parameterized interface as its default interface.

#### name

The fully qualified name of the specified interface group type.

#### elementCount

The number of elements in the *defaultInterfaceNameElements* array.

#### defaultInterfaceNameElements

An array, as would be returned by [RoParseTypeName](https://learn.microsoft.com/windows/desktop/api/rometadataresolution/nf-rometadataresolution-roparsetypename), that specifies a parameterized type instance.

### `SetRuntimeClassSimpleDefault`

Assigns a run-time class to the metadata builder.

#### name

The fully qualified name of the specified run-time class type.

#### defaultInterfaceName

The fully qualified name of the default interface (must be a non-parametric type).

#### defaultInterfaceIID

Optional.
If null, a separate call will be made to resolve the default interface type.
If not null, pointer to a GUID that contains the IID for the default interface named by *defaultInterfaceName*.

### `SetRuntimeClassParameterizedDefault`

Assigns a parameterized run-time class to the metadata builder.

#### name

The fully qualified name of the specified run-time class type.

#### elementCount

The number of elements in the *defaultInterfaceNameElements* array.

#### defaultInterfaceNameElements

An array, as would be returned by [RoParseTypeName](https://learn.microsoft.com/windows/desktop/api/rometadataresolution/nf-rometadataresolution-roparsetypename), that specified a parameterized type instance.

### `SetStruct`

Assigns a structure to the metadata builder.

#### name

The fully qualified name of the specified structure type.

#### numFields

The number of fields in the structure, specifying the length of the *fieldTypeNames* array.

#### fieldTypeNames

An array of strings specifying the types of each field in the structure, in the order that they appear in metadata. This order matches layout order in memory.

### `SetEnum`

Assigns an enumeration to the metadata builder.

The *baseType* of plain enumerations defaults to **Int32**. The *baseType* of flags enumerations defaults to **UInt32**.

#### name

The fully qualified name of the specified enumeration type.

#### baseType

The base type of the enumeration, as specified by the metadata.

### `SetParameterizedInterface`

Assigns a parameterized interface to the metadata builder.

This method is only for the non-instantiated parameterized interface. Instances are handled by [RoGetParameterizedTypeInstanceIID](https://learn.microsoft.com/windows/desktop/api/roparameterizediid/nf-roparameterizediid-rogetparameterizedtypeinstanceiid), and the caller does not need to parse them.

#### piid

The IID of the specified parameterized interface type.

#### numArgs

The number of type arguments required by the specified parameterized interface type.

### `SetParameterizedDelegate`

Assigns a parameterized delegate to the metadata builder.

This method is only for the non-instantiated parameterized interface. Instances are handled by [RoGetParameterizedTypeInstanceIID](https://learn.microsoft.com/windows/desktop/api/roparameterizediid/nf-roparameterizediid-rogetparameterizedtypeinstanceiid), and the caller does not need to parse them.

#### piid

The IID of the specified parameterized delegate type.

#### numArgs

The number of type arguments required by the specified parameterized delegate type.