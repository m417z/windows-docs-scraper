# FILTEROBJECT structure

The **FILTEROBJECT** structure defines a single object of a display filter. The [**FilterAddObject**](https://learn.microsoft.com/windows/win32/netmon2/filteraddobject) function uses **FILTEROBJECT** to build a display filter.

## Members

**Action**

Flag that specifies the **FILTEROBJECT** action. A flag can specify a property, value, or operator.

The following table lists Action member property flags.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------|
|

**FILTERACTION\_PROPERTY**

| Contains this property.<br> |
|

**FILTERACTION\_PROPERTYEXIST**

| Indicates that a filter action property is already defined.<br> |

The following table lists Action member value flags.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------|
|

**FILTERACTION\_VALUE**

| Contains this value.<br> |
|

**FILTERACTION\_STRING**

| Contains this string.<br> |
|

**FILTERACTION\_ARRAY**

| Contains this array.<br> |
|

**FILTERACTION\_CONTAINSNC**

| Indicates that a property contains a case-insensitive substring.<br> |
|

**FILTERACTION\_CONTAINS**

| Indicates that a property contains a case sensitive substring.<br> |
|

**FILTERACTION\_ADDRESS**

| Contains the MAC address.<br> |
|

**FILTERACTION\_ADDRESSANY**

| Matches any MAC address.<br> |
|

**FILTERACTION\_FROM**

| Indicates the **From MAC** address.<br> |
|

**FILTERACTION\_TO**

| Indicates the **To MAC** address.<br> |
|

**FILTERACTION\_FROMTO**

| Indicates a **From/To** pairing of MAC addresses.<br> |
|

**FILTERACTION\_LARGEINT**

| Contains a large integer.<br> |
|

**FILTERACTION\_TIME**

| Contains a **SYSTEMTIME** structure.<br> |
|

**FILTERACTION\_ADDR\_ETHER**

| Contains an Ethernet MAC address.<br> |
|

**FILTERACTION\_ADDR\_TOKEN**

| Contains a token ring MAC address.<br> |
|

**FILTERACTION\_ADDR\_FDDI**

| Contains a FDDI MAC address.<br> |
|

**FILTERACTION\_ADDR\_IPX**

| Contains an IPX MAC address.<br> |
|

**FILTERACTION\_ADDR\_IP**

| Contains an IP MAC address.<br> |
|

**FILTERACTION\_OID**

| Contains an Object Identifier (OID).<br> |

The following table lists Action member operator flags.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------|
|

**FILTERACTION\_INVALID**

| Indicates an invalid filter action.<br> |
|

**FILTERACTION\_AND**

| Indicates a logical **AND** statement.<br> |
|

**FILTERACTION\_OR**

| Indicates a logical **OR** statement.<br> |
|

**FILTERACTION\_XOR**

| Indicates a logical exclusive **OR** (XOR) statement.<br> |
|

**FILTERACTION\_NOT**

| Indicates a logical **NOT** statement.<br> |
|

**FILTERACTION\_EQUALNC**

| Filter action is equal and case insensitive.<br> |
|

**FILTERACTION\_EQUAL**

| Filter action is equal and case sensitive.<br> |
|

**FILTERACTION\_NOTEQUALNC**

| Logical **NOT** statement is equal and case insensitive.<br> |
|

**FILTERACTION\_NOTEQUAL**

| Logical **NOT** statement is equal and is case sensitive.<br> |
|

**FILTERACTION\_GREATERNC**

| Filter action is greater than (>) and case insensitive.<br> |
|

**FILTERACTION\_GREATER**

| Filter action is greater than (>) and case sensitive.<br> |
|

**FILTERACTION\_LESSNC**

| Filter action is less than (<) and case insensitive.<br> |
|

**FILTERACTION\_LESS**

| Filter action is less than (<) and case sensitive.<br> |
|

**FILTERACTION\_GREATEREQUALNC**

| Filter action is greater than or equal to (>=) and case insensitive.<br> |
|

**FILTERACTION\_GREATEREQUAL**

| Filter action is greater than or equal to (>=) and case sensitive.<br> |
|

**FILTERACTION\_LESSEQUALNC**

| Filter action is less than or equal to (<=) and case insensitive.<br> |
|

**FILTERACTION\_LESSEQUAL**

| Filter action is less than or equal to (<=) and is case sensitive.<br> |
|

**FILTERACTION\_PLUS**

| Add operator (+).<br> |
|

**FILTERACTION\_MINUS**

| Subtract operator (-).<br> |
|

**FILTERACTION\_AREBITSON**

| Indicates a bitwise operation.<br> |
|

**FILTERACTION\_AREBITSOFF**

| Indicates a non-bitwise operation.<br> |
|

**FILTERACTION\_PROTOCOLSEXIST**

| Indicates that the selected protocols exist.<br> |
|

**FILTERACTION\_PROTOCOLEXIST**

| Indicates that the selected protocol exists.<br> |
|

**FILTERACTION\_ARRAYEQUAL**

| Indicates that array contents are equal. The flag must be used with a **FILTERACTION\_ARRAY** structure.<br> |
|

**FILTERACTION\_DEREFPROPERTY**

| Describes a pattern match at an offset (in bytes), from the protocol.<br> |
|

**FILTERACTION\_OID\_CONTAINS**

| Evaluates a substring within an object identifier. The action must be used with the **FILTERACTION\_OID** structure.<br> |
|

**FILTERACTION\_OID\_BEGINS\_WITH**

| Evaluates a substring that begins an object identifier. The flag must be used with **FILTERACTION\_OID**.<br> |
|

**FILTERACTION\_OID\_ENDS\_WITH**

| Evaluates a substring that ends an object identifier. The flag must be used with **FILTERACTION\_OID**.<br> |
|

**FILTERACTION\_ADDR\_VINES**

| Contains a Vines MAC address.<br> |
|

**FILTERACTION\_EXPRESSION**

| Contains an action expression.<br> |
|

**FILTERACTION\_BOOL**

| Contains a **BOOL** data type.<br> |
|

**FILTER\_DIRECTION\_NEXT**

| Controls sequential direction (Next frame) within a capture file.<br> |
|

**FILTER\_DIRECTION\_PREV**

| Controls sequential direction (Previous frame) within a capture file.<br> |

**hProperty**

Handle to a property key.

**Value**

Value of an object.

**hProtocol**

Handle to display filter protocol.

**lpArray**

Pointer to an array.

**lpProtocolTable**

Pointer to a protocol list designed to test the existence of protocol in a frame.

**lpAddress**

Pointer to the kernel type address. For example, MAC or IP.

**lpLargeInt**

Double **DWORD** used in a Windows NT or Windows 2000 application.

**lpTime**

A pointer to a **SYSTEMTIME** structure.

**lpOID**

A pointer to the **OBJECT\_IDENTIFIER** (OID) structure.

**ByteCount**

The number, in bytes, in the frame.

**ByteOffset**

The offset byte value of the FILTEROBJECT structure used to compare arrays.

**pNext**

Reserved.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

