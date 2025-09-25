# TYPEFLAGS enumeration

## Description

The type flags.

## Constants

### `TYPEFLAG_FAPPOBJECT:0x1`

A type description that describes an Application object.

### `TYPEFLAG_FCANCREATE:0x2`

Instances of the type can be created by [ITypeInfo::CreateInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-createinstance).

### `TYPEFLAG_FLICENSED:0x4`

The type is licensed.

### `TYPEFLAG_FPREDECLID:0x8`

The type is predefined. The client application should automatically create a single instance of the object that has this attribute. The name of the variable that points to the object is the same as the class name of the object.

### `TYPEFLAG_FHIDDEN:0x10`

The type should not be displayed to browsers.

### `TYPEFLAG_FCONTROL:0x20`

The type is a control from which other types will be derived, and should not be displayed to users.

### `TYPEFLAG_FDUAL:0x40`

The interface supplies both [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) and VTBL binding.

### `TYPEFLAG_FNONEXTENSIBLE:0x80`

The interface cannot add members at run time.

### `TYPEFLAG_FOLEAUTOMATION:0x100`

The types used in the interface are fully compatible with Automation, including VTBL binding support. Setting dual on an interface sets this flag in addition to TYPEFLAG_FDUAL. Not allowed on dispinterfaces.

### `TYPEFLAG_FRESTRICTED:0x200`

Should not be accessible from macro languages. This flag is intended for system-level types or types that type browsers should not display.

### `TYPEFLAG_FAGGREGATABLE:0x400`

The class supports aggregation.

### `TYPEFLAG_FREPLACEABLE:0x800`

The type is replaceable.

### `TYPEFLAG_FDISPATCHABLE:0x1000`

Indicates that the interface derives from [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch), either directly or indirectly. This flag is computed. There is no Object Description Language for the flag.

### `TYPEFLAG_FREVERSEBIND:0x2000`

The type has reverse binding.

### `TYPEFLAG_FPROXY:0x4000`

Interfaces can be marked with this flag to indicate that they will be using a proxy/stub dynamic link library. This flag specifies that the typelib proxy should not be unregistered when the typelib is unregistered.

## Remarks

TYPEFLAG_FAPPOBJECT can be used on type descriptions with TypeKind = TKIND_COCLASS, and indicates that the type description specifies an Application object.

Members of the Application object are globally accessible. The [Bind](https://learn.microsoft.com/windows/desktop/api/oaidl/nf-oaidl-itypecomp-bind) method of the [ITypeComp](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypecomp) instance associated with the library binds to the members of an Application object, just as it does for type descriptions that have TypeKind = TKIND_MODULE.

The type description implicitly defines a global variable with the same name and type described by the type description. This variable is also globally accessible. When [Bind](https://learn.microsoft.com/windows/desktop/api/oaidl/nf-oaidl-itypecomp-bind) is passed the name of an Application object, a VARDESC is returned, which describes the implicit variable. The ID of the implicitly created variable is always ID_DEFAULTINST.

The [ITypeInfo::CreateInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-createinstance) function of an Application object type description is called, and then it uses [GetActiveObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-getactiveobject) to retrieve the Application object. If **GetActiveObject** fails because the application is not running, then **CreateInstance** calls **CoCreateInstance**, which should start the application.

When TYPEFLAG_FCANCREATE is set, [CreateInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-createinstance) can create an instance of this type. This is true only for component object classes for which a globally unique identifier (GUID) has been specified.