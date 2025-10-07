# DEVPROPERTY structure

Describes a property for a software device.

## Members

`CompKey`

A [**DEVPROPCOMPKEY**](https://learn.microsoft.com/windows-hardware/drivers/install/devpropcompkey) structure that represents a compound key for a property.

`Type`

A **DEVPROPTYPE** value that indicates the property type. Valid **DEVPROPTYPE** values are constructed from base DEVPROP\_TYPE\_ values, which may be modified by a logical OR with DEVPROP\_TYPEMOD\_ values, as appropriate.

Here are possible DEVPROP\_TYPE\_ values:

| Value | Meaning |
| -- | -- |
| [DEVPROP_TYPE_EMPTY](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-empty) 0x00000000 | Nothing, no property data |
| [DEVPROP_TYPE_NULL](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-null) 0x00000001 | Null property data |
| [DEVPROP_TYPE_SBYTE](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-sbyte) 0x00000002 | 8-bit signed int (SBYTE) |
| [DEVPROP_TYPE_BYTE](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-byte) 0x00000003 | 8-bit unsigned int (BYTE) |
| [DEVPROP_TYPE_INT16](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-int16) 0x00000004 | 16-bit signed int (SHORT) |
| [DEVPROP_TYPE_UINT16](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-uint16) 0x00000005 | 16-bit unsigned int (USHORT) |
| [DEVPROP_TYPE_INT32](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-int32) 0x00000006 | 32-bit signed int (LONG) |
| [DEVPROP_TYPE_UINT32](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-uint32) 0x00000007 | 32-bit unsigned int (ULONG) |
| [DEVPROP_TYPE_INT64](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-int64) 0x00000008 | 64-bit signed int (LONG64) |
| [DEVPROP_TYPE_UINT64](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-uint64) 0x00000009 | 64-bit unsigned int (ULONG64) |
| [DEVPROP_TYPE_FLOAT](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-float) 0x0000000A | 32-bit floating-point (FLOAT) |
| [DEVPROP_TYPE_DOUBLE](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-double) 0x0000000B | 64-bit floating-point (DOUBLE) |
| [DEVPROP_TYPE_DECIMAL](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-decimal) 0x0000000C | 128-bit data (DECIMAL) |
| [DEVPROP_TYPE_GUID](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-guid) 0x0000000D | 128-bit unique identifier (GUID) |
| [DEVPROP_TYPE_CURRENCY](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-currency) 0x0000000E | 64 bit signed int currency value (CURRENCY) |
| [DEVPROP_TYPE_DATE](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-date) 0x0000000F | date (DATE) |
| [DEVPROP_TYPE_FILETIME](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-filetime) 0x00000010 | file time (FILETIME) |
| [DEVPROP_TYPE_BOOLEAN](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-boolean) 0x00000011 | 8-bit boolean (DEVPROP_BOOLEAN) |
| [DEVPROP_TYPE_STRING](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-string) 0x00000012 | Null-terminated string |
| [DEVPROP_TYPE_STRING_LIST](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-string-list) (DEVPROP_TYPE_STRING \| DEVPROP_TYPEMOD_LIST) | Multi-sz string list |
| [DEVPROP_TYPE_SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-security-descriptor) 0x00000013 | Self-relative binary SECURITY_DESCRIPTOR |
| [DEVPROP_TYPE_SECURITY_DESCRIPTOR_STRING](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-security-descriptor-string) 0x00000014 | Security descriptor string (SDDL format) |
| [DEVPROP_TYPE_DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-devpropkey) 0x00000015 | Device property key (DEVPROPKEY) |
| [DEVPROP_TYPE_DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-devproptype) 0x00000016 | Device property type (DEVPROPTYPE) |
| [DEVPROP_TYPE_BINARY](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-binary) (DEVPROP_TYPE_BYTE \| DEVPROP_TYPEMOD_ARRAY) | Custom binary data |
| [DEVPROP_TYPE_ERROR](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-error) 0x00000017 | 32-bit Win32 system error code |
| [DEVPROP_TYPE_NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-ntstatus) 0x00000018 | 32-bit NTSTATUS code |
| [DEVPROP_TYPE_STRING_INDIRECT](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-string-indirect) 0x00000019 | String resource (@[path\]<dllname>,-<strId>) |

Here are possible DEVPROP\_TYPEMOD\_ values:

| Value | Meaning |
| -- | -- |
| [DEVPROP_TYPEMOD_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-typemod-array) 0x00001000 | Array of fixed-sized data elements |
| [DEVPROP_TYPEMOD_LIST](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-typemod-list) 0x00002000 | List of variable-sized data elements |

`BufferSize`

The size in bytes of the property in `Buffer`.

`Buffer`

The buffer that contains the property info.

This member can be a **PBYTE** type if **MIDL\_PASS** is defined:

```cpp
  #ifdef MIDL_PASS
        [size_is(BufferSize)] PBYTE Buffer;
    #else
        __field_bcount_opt(BufferSize) PVOID Buffer;
    #endif
```
## Requirements

|  |  |
| --- | --- |
| Header | Devpropdef.h |

## See also

[**SW\_DEVICE\_CREATE\_INFO**](https://learn.microsoft.com/windows/win32/api/swdevicedef/ns-swdevicedef-sw_device_create_info)