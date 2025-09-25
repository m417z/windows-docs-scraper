# FUNCFLAGS enumeration

## Description

Specifies function flags.

## Constants

### `FUNCFLAG_FRESTRICTED:0x1`

The function should not be accessible from macro languages. This flag is intended for system-level functions or functions that type browsers should not display.

### `FUNCFLAG_FSOURCE:0x2`

The function returns an object that is a source of events.

### `FUNCFLAG_FBINDABLE:0x4`

The function that supports data binding.

### `FUNCFLAG_FREQUESTEDIT:0x8`

When set, any call to a method that sets the property results first in a call to **IPropertyNotifySink::OnRequestEdit**. The implementation of **OnRequestEdit** determines if the call is allowed to set the property.

### `FUNCFLAG_FDISPLAYBIND:0x10`

The function that is displayed to the user as bindable. FUNC_FBINDABLE must also be set.

### `FUNCFLAG_FDEFAULTBIND:0x20`

The function that best represents the object. Only one function in a type information can have this attribute.

### `FUNCFLAG_FHIDDEN:0x40`

The function should not be displayed to the user, although it exists and is bindable.

### `FUNCFLAG_FUSESGETLASTERROR:0x80`

The function supports **GetLastError**. If an error occurs during the function, the caller can call **GetLastError** to retrieve the error code.

### `FUNCFLAG_FDEFAULTCOLLELEM:0x100`

Permits an optimization in which the compiler looks for a member named xyz on the type of abc. If such a member is found and is flagged as an accessor function for an element of the default collection, then a call is generated to that member function. Permitted on members in dispinterfaces and interfaces; not permitted on modules. For more information, refer to defaultcollelem in Type Libraries and the Object Description Language.

### `FUNCFLAG_FUIDEFAULT:0x200`

The type information member is the default member for display in the user interface.

### `FUNCFLAG_FNONBROWSABLE:0x400`

The property appears in an object browser, but not in a properties browser.

### `FUNCFLAG_FREPLACEABLE:0x800`

Tags the interface as having default behaviors.

### `FUNCFLAG_FIMMEDIATEBIND:0x1000`

Mapped as individual bindable properties.

## Remarks

FUNCFLAG_FHIDDEN means that the property should never be shown in object browsers, property browsers, and so on. This function is useful for removing items from an object model. Code can bind to the member, but the user will never know that the member exists.

FUNCFLAG_FNONBROWSABLE means that the property should not be displayed in a properties browser. It is used in circumstances in which an error would occur if the property were shown in a properties browser.

FUNCFLAG_FRESRICTED means that macro-oriented programmers should not be allowed to access this member. These members are usually treated as _FHIDDEN by tools such as Visual Basic, with the main difference being that code cannot bind to those members.