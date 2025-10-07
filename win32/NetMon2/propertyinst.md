# PROPERTYINST structure

The **PROPERTYINST** structure defines an instance of a property in a piece of recognized data. Network Monitor allocates and fills in a **PROPERTYINST** structure when a property is attached to the capture.

## Members

**lpPropertyInfo**

Pointer to the [PROPERTYINFO](https://learn.microsoft.com/windows/win32/netmon2/propertyinfo) structure that defines the property.

**szPropertyText**

Pointer to a string that is displayed in the details pane of the Network Monitor UI.

**lpData**

Pointer to the start of the data for the property. The parser determines where the property data starts.

**lpByte**

Pointer to the **BYTE** data.

**lpWord**

Pointer to the **WORD** data.

**lpDword**

Pointer to the **DWORD** data.

**lpLargeInt**

Pointer to the [**LARGEINT**](https://learn.microsoft.com/windows/win32/netmon2/largeint) data.

**lpSysTime**

Pointer to the [**SYSTEMTIME**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) data.

**lpPropertyInstEx**

Pointer to a [PROPERTYINSTEX](https://learn.microsoft.com/windows/win32/netmon2/propertyinstex) structure. The **lpPropertyInstEx** member is used only when you call [AttachPropertyInstanceEx](https://learn.microsoft.com/windows/win32/netmon2/attachpropertyinstanceex).

If **lpPropertyInstEx** is used, you must set the **DataLength** member to 0xFFFF.

**DataLength**

Data length for this instance of the property. If the **lpPropertyInstEx** member points to a [**PROPERTYINSTEX**](https://learn.microsoft.com/windows/win32/netmon2/propertyinstex) structure, you must set **DataLength** to 0xFFFF.

**Level**

Level information.

**HelpID**

Help file context identifier.

**IFlags**

Error condition flag.

## Remarks

The **PROPERTYINST** structure defines an instance of an attached property. The parser accesses the **PROPERTYINST** structure through several helper functions. For example, when the [**FormatPropertyInstance**](https://learn.microsoft.com/windows/win32/netmon2/formatpropertyinstance) function is called to format the data of a property, it modifies the **szPropertyText** member of the **PROPERTYINST** structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[AttachPropertyInstance](https://learn.microsoft.com/windows/win32/netmon2/attachpropertyinstance)

[AttachPropertyInstanceEx](https://learn.microsoft.com/windows/win32/netmon2/attachpropertyinstanceex)

