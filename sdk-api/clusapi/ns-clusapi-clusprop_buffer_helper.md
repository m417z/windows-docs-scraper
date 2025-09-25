# CLUSPROP_BUFFER_HELPER structure

## Description

Used to build or parse a [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) or, a
[value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists).

## Members

### `pb`

Pointer to a buffer containing an array of bytes.

### `pw`

Pointer to a buffer containing an array of **WORD** values.

### `pdw`

Pointer to a buffer containing an array of **DWORD** values.

### `pl`

Pointer to a buffer containing an array of signed **long** values.

### `psz`

Pointer to a buffer containing a **NULL**-terminated Unicode string value.

### `pList`

Pointer to a [CLUSPROP_LIST](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_list) structure describing the
beginning of a property list.

### `pSyntax`

Pointer to a [CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax) structure describing
the format and type of a value.

### `pName`

Pointer to a [CLUSPROP_PROPERTY_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368382(v=vs.85))
structure containing a property name value.

### `pValue`

Pointer to a [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure describing the
format, type, and length of a data value.

### `pBinaryValue`

Pointer to a [CLUSPROP_BINARY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_binary) structure containing a
binary data value.

### `pWordValue`

Pointer to a [CLUSPROP_WORD](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_word) structure containing a
numeric value.

### `pDwordValue`

Pointer to a [CLUSPROP_DWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368375(v=vs.85)) structure containing a
numeric value.

### `pLongValue`

Pointer to a [CLUSPROP_LONG](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_long) structure containing a
signed long value.

### `pULargeIntegerValue`

Pointer to a [CLUSPROP_ULARGE_INTEGER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_ularge_integer)
structure containing an unsigned large integer value.

### `pLargeIntegerValue`

Pointer to a [CLUSPROP_LARGE_INTEGER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_large_integer)
structure containing a large integer value.

### `pStringValue`

Pointer to a [CLUSPROP_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368390(v=vs.85)) structure containing a
**NULL**-terminated Unicode string value.

### `pMultiSzValue`

Pointer to a [CLUSPROP_MULTI_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_sz) structure
containing multiple null-terminated Unicode string values.

### `pSecurityDescriptor`

Pointer to a
[CLUSPROP_SECURITY_DESCRIPTOR](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_security_descriptor) structure
containing a security descriptor.

### `pResourceClassValue`

Pointer to a [CLUSPROP_RESOURCE_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_resource_class)
structure containing a resource class value.

### `pResourceClassInfoValue`

Pointer to a
[CLUSPROP_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_resource_class_info) structure
containing a resource class information value.

### `pDiskSignatureValue`

Pointer to a [CLUSPROP_DISK_SIGNATURE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368374(v=vs.85))
structure containing a disk signature value.

### `pScsiAddressValue`

Pointer to a [CLUSPROP_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_scsi_address)
structure containing an [SCSI](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly)
address value.

### `pDiskNumberValue`

Pointer to a [CLUSPROP_DISK_NUMBER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_dword) structure
containing a disk number value.

### `pPartitionInfoValue`

Pointer to a [CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info)
structure containing a partition information value.

### `pRequiredDependencyValue`

Pointer to a
[CLUSPROP_REQUIRED_DEPENDENCY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_required_dependency) structure
containing a resource dependency value.

### `pPartitionInfoValueEx`

Pointer to a
[CLUSPROP_PARTITION_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info_ex) structure
containing a partition information value.

### `pPartitionInfoValueEx2`

A pointer to a [CLUSPROP_PARTITION_INFO_EX2](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info_ex2) structure
that contains a partition information value.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This member is not available before Windows Server 2016.

### `pFileTimeValue`

Pointer to a [CLUSPROP_FILETIME](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_filetime) structure
containing a date/time value.

## Remarks

The **CLUSPROP_BUFFER_HELPER** structure is useful
in working with property and value lists. Applications can use a generic
**CLUSPROP_BUFFER_HELPER** pointer to advance by
offsets through the entries of a property list or value list, retrieving or setting values without having to cast
to the appropriate data type.

An alternate structure, [RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item),
can also be used to work with multiple properties.

Use caution when referencing large integer values in **DWORD**-aligned structures
such as value lists, property lists, and
[parameter blocks](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/parameter-blocks). For Windows Server for Itanium-based
systems, a naturally-aligned large integer value always begins on an address ending in 0 or 8h.
**DWORD** alignment can cause large values to begin on unaligned boundaries (addresses
ending in 4h or C), which will cause an alignment fault when the data is read or written. You can avoid alignment
faults by handling the high and low parts of large values separately, or by using local variables, which are
guaranteed to be naturally aligned.

#### Examples

In addition to the following example, see
[Creating Property Lists](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/creating-property-lists),
[Parsing Property Lists](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/parsing-property-lists),
[Creating Value Lists](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/creating-value-lists), and
[Parsing a Value List](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/parsing-a-value-list).

```cpp
//////////////////////////////////////////////////////////////////////
//
//    HOW TO USE CLUSPROP_BUFFER HELPER
//
//    (1) Position cbh to the next read or write location.
//    (2) Read or write data using an appropriate pointer.
//    (3) Check position within buffer.
//
//    Repeat (1)(2)(3)
//
//////////////////////////////////////////////////////////////////////
void ClusDocEx_UsingCBH()
{
    LPVOID lp = LocalAlloc( LPTR, 100 ); // It is important for cbh
                                         // to know the allocated
                                         // size.
    CLUSPROP_BUFFER_HELPER cbh;

// ( 1 )
//
//    Position cbh.  The pb member is convenient for
//    targeting single bytes.
//

      cbh.pb = (LPBYTE) lp;

//
//    The pb member points to the first byte of lp.
//
//    lp -----> 0 0 0 0 0 0 0 0 0 0 0 ... 0
//
//    cbh.pb-->|-|
//
//
//    Note what happens when different cbh pointer types are used:
//
//                   lp -----> 0 0 0 0 0 0 0 0 0 0 0 0 ... 0
//
//    cbh.pdw              -->|-------|
//    cbh.psz              -->|-|
//    cbh.pValue           -->|---------------|
//    cbh.pValue->Syntax.dw-->|-------|
//    cbh.pValue->cbLength         -->|-------|
//
//
//    The configuration of bytes that will be affected by a read
//    or write operation depends on the type of pointer used.
//

// ( 2 )
//
//    Read or write data to the present location.  Note how the
//    structure pointers let you "reach over" intervening members.
//

      cbh.pValue->Syntax.dw = CLUSPROP_SYNTAX_LIST_VALUE_DWORD;

      cbh.pValue->cbLength = sizeof( DWORD );

      cbh.pDwordValue->dw  = 0x0000EEEEL;

//
//    Result:   lp ----->| syntax | length |  value  | 0 0 0 0 ... 0
//

// ( 3 )
//
//    Check your remaining space.  Be sure you have room to advance
//    cbh past the current data and perform a read operation on the
//    next value.
//

      DWORD cbPosition = cbh.pb - (LPBYTE) lp;

      DWORD cbAdvance = ClusDocEx_ListEntrySize( sizeof( DWORD ) );  // See "ClusDocEx.h"

      if( ( cbPosition + cbAdvance + sizeof( DWORD ) ) > 100 )
      {
          // handle the fact that there's more data than the reported size of the buffer
      }

//
//    Repeat ( 1 ), ( 2 ), and ( 3 ) for the next value:
//

      // Position cbh

      cbh.pb += cbAdvance;

      // Write next entry

      cbh.pStringValue->Syntax.dw = CLUSPROP_SYNTAX_LIST_VALUE_SZ;

      cbh.pStringValue->cbLength = ( lstrlenW( L"String Value" ) + 1 ) * sizeof( WCHAR );

      StringCchCopyW( cbh.pStringValue->sz, cbh.pStringValue->cbLength, L"String Value" );

      // Check space

      cbPosition = cbh.pb - (LPBYTE) lp;

      cbAdvance = ClusDocEx_ListEntrySize( cbh.pStringValue->cbLength );

      if( ( cbPosition + cbAdvance + sizeof( DWORD ) ) > 100 )
      {
          //
      }

//
//    Repeat ( 1 ), ( 2 ), and ( 3 )  until all values have been written or read.
//

      cbh.pb = NULL;

      LocalFree( lp );
}

```

## See also

[CLUSPROP_BINARY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_binary)

[CLUSPROP_DISK_NUMBER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_dword)

[CLUSPROP_DISK_SIGNATURE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368374(v=vs.85))

[CLUSPROP_DWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368375(v=vs.85))

[CLUSPROP_LIST](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_list)

[CLUSPROP_MULTI_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_sz)

[CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info)

[CLUSPROP_PROPERTY_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368382(v=vs.85))

[CLUSPROP_REQUIRED_DEPENDENCY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_required_dependency)

[CLUSPROP_RESOURCE_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_resource_class)

[CLUSPROP_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_resource_class_info)

[CLUSPROP_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_scsi_address)

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368390(v=vs.85))

[CLUSPROP_ULARGE_INTEGER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_ularge_integer)

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)