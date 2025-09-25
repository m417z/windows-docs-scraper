# RESUTIL_PROPERTY_ITEM structure

## Description

Contains
information about a cluster object property. An array of
**RESUTIL_PROPERTY_ITEM** structures forms a
[property table](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-tables) which can be used in property operations.

## Members

### `Name`

The name of the property.

### `KeyName`

Optional name of the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) subkey for
the property. This parameter can be **NULL**.

### `Format`

Describes the format of the property such as **CLUSPROP_FORMAT_BINARY** or
**CLUSPROP_FORMAT_DWORD**. For a list of valid format values, see the
**wFormat** member of
[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax).

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DefaultPtr`

### `DUMMYUNIONNAME.Default`

### `DUMMYUNIONNAME.lpDefault`

### `DUMMYUNIONNAME.LargeIntData`

### `DUMMYUNIONNAME.ULargeIntData`

### `DUMMYUNIONNAME.FileTimeData`

### `Minimum`

Minimum data value for the property. For data values with the
**CLUSPROP_FORMAT_BINARY** and **CLUSPROP_FORMAT_MULTI_SZ**
formats, the **Minimum** member contains the byte size of the default data value
specified by **Default**.

### `Maximum`

Maximum data value for the property.

### `Flags`

Bitmask that describes the property.

#### RESUTIL_PROPITEM_READ_ONLY (0x00000001)

The property is [read-only](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/read-only-properties).

#### RESUTIL_PROPITEM_REQUIRED (0x00000002)

The property is required.

#### RESUTIL_PROPITEM_SIGNED (0x00000004)

Flags a numeric property as a signed value.

### `Offset`

Byte offset to the actual property data. The data is stored in a buffer known as a parameter block.

#### - ( unnamed union )

The default value of the property in one of the following forms.

#### DefaultPtr

Pointer to a **DWORD** default value.

#### Default

A **DWORD** default value.

#### lpDefault

Void pointer to a buffer containing the default value.

#### LargeIntData

Pointer to a [RESUTIL_LARGEINT_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_largeint_data)
structure describing the maximum, minimum, and default values for a signed large integer.

#### ULargeIntData

Pointer to a [RESUTIL_ULARGEINT_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_ulargeint_data)
structure describing the maximum, minimum, and default values for an unsigned large integer. The default value
must be consistent with the format specified by the **Format** member.

#### FileTimeData

Pointer to a [RESUTIL_FILETIME_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_filetime_data)
structure describing the file data and time data.

## Remarks

For more information about building parameter blocks and property tables, see
[Using Lists and Tables](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-lists-and-tables).

#### Examples

See [Using Lists and Tables](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-lists-and-tables) and
[Building with CLUSPROP_BUFFER_HELPER](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/building-with-clusprop-buffer-helper),
and [Defining Structures and Constants](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/defining-structures-and-constants) in
[Implementing Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-resource-dlls).

## See also

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)