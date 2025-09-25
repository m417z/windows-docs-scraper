# AUDIT_PARAM_TYPE enumeration

## Description

The **AUDIT_PARAM_TYPE** enumeration defines the type of audit parameters that are available.

## Constants

### `APT_None`

No audit options.

### `APT_String`

A string that terminates with **NULL**.

### `APT_Ulong`

An unsigned long.

### `APT_Pointer`

A pointer that is used to specify handles and pointers. These are 32-bit on 32-bit systems and 64-bit on 64-bit systems. Use this option when you are interested in the absolute value of the pointer. The memory to which the pointer points is not marshaled when using this type.

### `APT_Sid`

The [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

### `APT_LogonId`

The logon identifier (LUID) that results in three output parameters:

* Account name
* Authority name
* LogonID""

### `APT_ObjectTypeList`

Object type list.

### `APT_Luid`

LUID that is not translated to LogonId.

### `APT_Guid`

GUID.

### `APT_Time`

Time as FILETIME.

### `APT_Int64`

ULONGLONG.

### `APT_IpAddress`

IP Address (IPv4 and IPv6). This logs the address as the first parameter and the port as the second parameter. You must ensure that two entries are added in the event message file. You should ensure that the buffer size is 128 bytes.

### `APT_LogonIdWithSid`

Logon ID with SID that results in four output parameters:

* SID
* Account name
* Authority name
* LogonID