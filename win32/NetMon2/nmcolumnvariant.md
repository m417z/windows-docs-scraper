# NMCOLUMNVARIANT structure

The **NMCOLUMNVARIANT** structure provides a line in the top pane of the Event Viewer that serves as a container for all possible data inserted into a column.

## Members

**Type**

A value from the [**NMCOLUMNTYPE**](https://learn.microsoft.com/windows/win32/netmon2/nmcolumntype) enumeration type.

**Value**

**Uint8Val**

8-bit unsigned integer value.

**Sint8Val**

8-bit signed integer value.

**Uint16Val**

16-bit unsigned integer value.

**Sint16Val**

16-bit signed integer value.

**Uint32Val**

32-bit unsigned integer value.

**Sint32Val**

32-bit signed integer value.

**Float64Val**

64-bit float value.

**FrameVal**

Frame number.

**YesNoVal**

Displays Yes or No.

**OnOffVal**

Displays On or Off.

**TrueFalseVal**

Displays True or False.

**MACAddrVal**

MAC address.

**IPXAddrVal**

IPX address.

**IPAddrVal**

IP address.

**VarTimeVal**

Variant time. Use **VariantTimetoSystemTime** to convert to system time.

**pStringVal**

Pointer to a string.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[**NMCOLUMNTYPE**](https://learn.microsoft.com/windows/win32/netmon2/nmcolumntype)

