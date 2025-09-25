## Description

A GUID identifies an object such as a COM interfaces, or a COM class object, or a manager entry-point vector (EPV). A GUID is a 128-bit value consisting of one group of 8 hexadecimal digits, followed by three groups of 4 hexadecimal digits each, followed by one group of 12 hexadecimal digits. The following example GUID shows the groupings of hexadecimal digits in a GUID: 6B29FC40-CA47-1067-B31D-00DD010662DA.

The **GUID** structure stores a GUID.

## Members

### `Data1`

Specifies the first 8 hexadecimal digits of the GUID.

### `Data2`

Specifies the first group of 4 hexadecimal digits.

### `Data3`

Specifies the second group of 4 hexadecimal digits.

### `Data4`

Array of 8 bytes. The first 2 bytes contain the third group of 4 hexadecimal digits. The remaining 6 bytes contain the final 12 hexadecimal digits.

## Remarks

GUIDs are the Microsoft implementation of the distributed computing environment (DCE) universally unique identifier ([UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid)). The RPC run-time libraries use UUIDs to check for compatibility between clients and servers and to select among multiple implementations of an interface. The Windows access-control functions use GUIDs to identify the type of object that an object-specific ACE in an access-control list (ACL) protects.

## See also

**ACCESS\_ALLOWED\_OBJECT\_ACE**
**ACE**
**ACL**
[UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid)
[UUID\_VECTOR](https://learn.microsoft.com/windows/win32/api/rpcdce/ns-rpcdce-uuid_vector)