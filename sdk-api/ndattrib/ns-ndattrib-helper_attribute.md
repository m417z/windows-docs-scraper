# HELPER_ATTRIBUTE structure

## Description

The **HELPER_ATTRIBUTE** structure contains all NDF supported data types.

## Members

### `pwszName`

Type: **[string] LPWSTR**

A pointer to a null-terminated string that contains the name of the attribute.

### `type`

Type: **[ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/ndattrib/ne-ndattrib-attribute_type)**

The type of helper attribute.

### `Boolean`

Type: **BOOL**

A True or False value. Used when **type** is **AT_BOOLEAN**.

### `Char`

Type: **char**

A character value. Used when **type** is **AT_INT8**.

### `Byte`

Type: **byte**

A byte value. Used when **type** is **AT_UINT8**.

### `Short`

Type: **short**

A 16-bit signed value. Used when **type** is **AT_INT16**

### `Word`

Type: **WORD**

A 2-byte unsigned value. Used when **type** is **AT_UINT16**.

### `Int`

Type: **int**

A 4-byte signed value. Used when **type** is **AT_INT32**.

### `DWord`

Type: **DWORD**

A 4-byte unsigned value. Used when **type** is **AT_UINT32**.

### `Int64`

Type: **LONGLONG**

A 64-bit signed integer value. Used when **type** is **AT_INT64**.

### `UInt64`

Type: **ULONGLONG**

A 64-bit unsigned integer value. Used when **type** is **AT_UINT64**.

### `PWStr`

Type: **LPWSTR**

A null-terminated string value. Used when **type** is **AT_STRING**.

### `Guid`

Type: **GUID**

A GUID structure. Used when **type** is **AT_GUID**.

### `LifeTime`

Type: **[LIFE_TIME](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-life_time)**

A [LIFE_TIME](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-life_time) structure. Used when **type** is **AT_LIFE_TIME**.

### `Address`

Type: **[DIAG_SOCKADDR](https://learn.microsoft.com/windows/win32/api/ndattrib/ns-ndattrib-diag_sockaddr)**

An IPv4 or IPv6 address. Used when **type** is **AT_SOCKADDR**.

### `OctetString`

Type: **[OCTET_STRING](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-octet_string)**

A byte array for undefined types. Used when **type** is **AT_OCTET_STRING**.

## See also

[ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/ndattrib/ne-ndattrib-attribute_type)

[CopyHelperAttribute](https://learn.microsoft.com/windows/desktop/NDF/copyhelperattribute)

[FreeHelperAttributes](https://learn.microsoft.com/windows/desktop/NDF/freehelperattributes)