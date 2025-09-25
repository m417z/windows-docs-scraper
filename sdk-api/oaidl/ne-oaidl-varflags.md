# VARFLAGS enumeration

## Description

Specifies variable flags.

## Constants

### `VARFLAG_FREADONLY:0x1`

Assignment to the variable should not be allowed.

### `VARFLAG_FSOURCE:0x2`

The variable returns an object that is a source of events.

### `VARFLAG_FBINDABLE:0x4`

The variable supports data binding.

### `VARFLAG_FREQUESTEDIT:0x8`

When set, any attempt to directly change the property results in a call to **IPropertyNotifySink::OnRequestEdit**. The implementation of **OnRequestEdit** determines if the change is accepted.

### `VARFLAG_FDISPLAYBIND:0x10`

The variable is displayed to the user as bindable. VARFLAG_FBINDABLE must also be set.

### `VARFLAG_FDEFAULTBIND:0x20`

The variable is the single property that best represents the object. Only one variable in type information can have this attribute.

### `VARFLAG_FHIDDEN:0x40`

The variable should not be displayed to the user in a browser, although it exists and is bindable.

### `VARFLAG_FRESTRICTED:0x80`

The variable should not be accessible from macro languages. This flag is intended for system-level variables or variables that you do not want type browsers to display.

### `VARFLAG_FDEFAULTCOLLELEM:0x100`

Permits an optimization in which the compiler looks for a member named "xyz" on the type of abc. If such a member is found and is flagged as an accessor function for an element of the default collection, then a call is generated to that member function. Permitted on members in dispinterfaces and interfaces; not permitted on modules.

### `VARFLAG_FUIDEFAULT:0x200`

The variable is the default display in the user interface.

### `VARFLAG_FNONBROWSABLE:0x400`

The variable appears in an object browser, but not in a properties browser.

### `VARFLAG_FREPLACEABLE:0x800`

Tags the interface as having default behaviors.

### `VARFLAG_FIMMEDIATEBIND:0x1000`

The variable is mapped as individual bindable properties.