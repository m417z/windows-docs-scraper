# IMAGEHLP_GET_TYPE_INFO_PARAMS structure

## Description

Contains type information for a module.

## Members

### `SizeOfStruct`

The size of this structure, in bytes.

### `Flags`

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **IMAGEHLP_GET_TYPE_INFO_CHILDREN**<br><br>0x00000002 | Retrieve information about the children of the specified types, not the types themselves. |
| **IMAGEHLP_GET_TYPE_INFO_UNCACHED**<br><br>0x00000001 | Do not cache the data for later retrievals. It is good to use this flag if you will not be requesting the information again. |

### `NumIds`

The number of elements specified in the **TypeIds** array.

### `TypeIds`

An array of type indexes.

### `TagFilter`

The filter for return values. For example, set this member to 1 << **SymTagData** to return only results with a symbol tag of **SymTagData**. For a list of tags, see the **SymTagEnum** type defined in Dbghelp.h

### `NumReqs`

The number of elements specified in the arrays specified in the **ReqKinds**, **ReqOffsets**, and **ReqSizes** members. These arrays must be the same size.

### `ReqKinds`

An array of information types to be requested. Each element is one of the enumeration values in the [IMAGEHLP_SYMBOL_TYPE_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ne-dbghelp-imagehlp_symbol_type_info) enumeration type.

### `ReqOffsets`

An array of offsets that specify where to store the data for each request within each element of **Buffer** array.

### `ReqSizes`

The size of each data request, in bytes. The required sizes are described in [IMAGEHLP_SYMBOL_TYPE_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ne-dbghelp-imagehlp_symbol_type_info).

### `ReqStride`

The number of bytes for each element in the **Buffer** array.

### `BufferSize`

The size of the **Buffer** array, in bytes.

### `Buffer`

An array of records used for storing query results. Each record is separated by **ReqStride** bytes. Each type for which data is to be retrieved requires one record in the array. Within each record, there are **NumReqs** pieces of data stored as the result of individual queries. The data is stored within the record according to the offsets specified in **ReqOffsets**. The format of the data depends on the value of the **ReqKinds** member in use.

### `EntriesMatched`

The number of type entries that match the filter.

### `EntriesFilled`

The number of elements in the **Buffer** array that received results.

### `TagsFound`

A bitmask indicating all tag bits encountered during the search operation.

### `AllReqsValid`

A bitmask indicate the bit-wise AND of all **ReqsValid** fields.

### `NumReqsValid`

The size of **ReqsValid**, in elements.

### `ReqsValid`

A bitmask indexed by **Buffer** element index that indicates which request data is valid. This member can be **NULL**.

## See also

[IMAGEHLP_SYMBOL_TYPE_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ne-dbghelp-imagehlp_symbol_type_info)

[SymGetTypeInfoEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgettypeinfoex)