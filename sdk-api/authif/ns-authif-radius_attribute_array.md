# RADIUS_ATTRIBUTE_ARRAY structure

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The
**RADIUS_ATTRIBUTE_ARRAY** structure represents an array of attributes.

## Members

### `cbSize`

Specifies the size of the structure.

### `Add`

Pointer to the [Add](https://learn.microsoft.com/previous-versions/ms688246(v=vs.85)) function provided by NPS. NPS sets the value of the member.

#### This

Pointer to the
**RADIUS_ATTRIBUTE_ARRAY** structure that represents the array of attributes to which to append the specified attribute.

The
[GetRequest](https://learn.microsoft.com/previous-versions/ms688263(v=vs.85)) and
[GetResponse](https://learn.microsoft.com/previous-versions/ms688270(v=vs.85)) functions return pointers to
**RADIUS_ATTRIBUTE_ARRAY** structures.

#### pAttr

Pointer to a
[RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_attribute) structure for the attribute to append to the array.

### `AttributeAt`

Pointer to the [AttributeAt](https://learn.microsoft.com/previous-versions/ms688253(v=vs.85)) function provided by NPS. NPS sets the value of the member.

The
[AttributeAt](https://learn.microsoft.com/previous-versions/ms688253(v=vs.85)) function returns a const pointer to the specified attribute within the array.

#### This

Pointer to the
**RADIUS_ATTRIBUTE_ARRAY** structure that represents the array of attributes from which to retrieve the specified attribute.

The
[GetRequest](https://learn.microsoft.com/previous-versions/ms688263(v=vs.85)) and
[GetResponse](https://learn.microsoft.com/previous-versions/ms688270(v=vs.85)) functions return pointers to
**RADIUS_ATTRIBUTE_ARRAY** structures.

#### dwIndex

Specifies the index of the attribute to retrieve. The function returns **NULL** if this index is out of range.

Use the
[GetSize](https://learn.microsoft.com/previous-versions/ms688277(v=vs.85)) function to determine the size of the array. The largest index is one less than the size of the array.

### `GetSize`

Pointer to the [GetSize](https://learn.microsoft.com/previous-versions/ms688277(v=vs.85)) function provided by NPS. NPS sets the value of the member.

The
[GetSize](https://learn.microsoft.com/previous-versions/ms688277(v=vs.85)) function returns the size of the attribute array.

The
[GetSize](https://learn.microsoft.com/previous-versions/ms688277(v=vs.85)) function returns the size of the attribute array, not the largest index. Because attribute arrays use zero-based indexes, the size of the array is one greater than the largest index.

#### This

Pointer to the
**RADIUS_ATTRIBUTE_ARRAY** structure that represents the array of attributes for which to retrieve the size.

The
[GetRequest](https://learn.microsoft.com/previous-versions/ms688263(v=vs.85)) and
[GetResponse](https://learn.microsoft.com/previous-versions/ms688270(v=vs.85)) functions return pointers to
**RADIUS_ATTRIBUTE_ARRAY** structures.

### `InsertAt`

Pointer to the [InsertAt](https://learn.microsoft.com/previous-versions/ms688296(v=vs.85)) function provided by NPS. NPS sets the value of the member.

The
[InsertAt](https://learn.microsoft.com/previous-versions/ms688296(v=vs.85)) function inserts the specified attribute at the specified index in the array.

When the
[InsertAt](https://learn.microsoft.com/previous-versions/ms688296(v=vs.85)) function inserts a new attribute into the array, it increments the index of the pre-existing attribute at this index. Similarly, it increments the index of any pre-existing attributes at higher indexes.

To append an attribute to the end of the attribute array, use the
[Add](https://learn.microsoft.com/previous-versions/ms688246(v=vs.85)) function.

#### This

Pointer to the
**RADIUS_ATTRIBUTE_ARRAY** structure that represents the array of attributes in which to insert the specified attribute.

The
[GetRequest](https://learn.microsoft.com/previous-versions/ms688263(v=vs.85)) and
[GetResponse](https://learn.microsoft.com/previous-versions/ms688270(v=vs.85)) functions return pointers to
**RADIUS_ATTRIBUTE_ARRAY** structures.

#### dwIndex

Specifies the index at which to insert the specified attribute.

Use the
[GetSize](https://learn.microsoft.com/previous-versions/ms688277(v=vs.85)) function to determine the size of the array. The largest index is one less than the size of the array.

#### pAttr

Pointer to a
[RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_attribute) structure for the attribute to insert into the array.

### `RemoveAt`

Pointer to the [RemoveAt](https://learn.microsoft.com/previous-versions/ms688452(v=vs.85)) function provided by NPS. NPS sets the value of the member.

The
[RemoveAt](https://learn.microsoft.com/previous-versions/ms688452(v=vs.85)) function removes the attribute at the specified index in the array.

When the [RemoveAt](https://learn.microsoft.com/previous-versions/ms688452(v=vs.85)) function removes an attribute from the array, it decrements the index of any pre-existing attributes at higher indexes.

#### This

Pointer to the
**RADIUS_ATTRIBUTE_ARRAY** structure that represents the array of attributes from which to remove the specified attribute.

The
[GetRequest](https://learn.microsoft.com/previous-versions/ms688263(v=vs.85)) and
[GetResponse](https://learn.microsoft.com/previous-versions/ms688270(v=vs.85)) functions return pointers to
**RADIUS_ATTRIBUTE_ARRAY** structures.

#### dwIndex

Specifies the index of the attribute to remove.

Use the
[GetSize](https://learn.microsoft.com/previous-versions/ms688277(v=vs.85)) function to determine the size of the array. The largest index is one less than the size of the array.

### `SetAt`

Pointer to the [SetAt](https://learn.microsoft.com/previous-versions/ms688456(v=vs.85)) function provided by NPS. NPS sets the value of the member.

The
[SetAt](https://learn.microsoft.com/previous-versions/ms688456(v=vs.85)) function replaces the attribute at the specified index with the specified attribute.

#### This

Pointer to the
**RADIUS_ATTRIBUTE_ARRAY** structure that represents the array of attributes that contains the attribute to replace.

The
[GetRequest](https://learn.microsoft.com/previous-versions/ms688263(v=vs.85)) and
[GetResponse](https://learn.microsoft.com/previous-versions/ms688270(v=vs.85)) functions return pointers to
**RADIUS_ATTRIBUTE_ARRAY** structures.

#### dwIndex

Specifies the index of the attribute to replace.

Use the
[GetSize](https://learn.microsoft.com/previous-versions/ms688277(v=vs.85)) function to determine the size of the array. The largest index is one less than the size of the array.

#### pAttr

Pointer to a
[RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_attribute) structure. The attribute represented by this structure replaces the attribute at the specified index.

## Remarks

The Extension DLL must not modify this structure. Changes to the array of attributes should be made by calling the functions provided as members of this structure.

This structure is used by Extension DLLs that export
[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2). The functions that add attributes to the array:

[Add](https://learn.microsoft.com/previous-versions/ms688246(v=vs.85))
[InsertAt](https://learn.microsoft.com/previous-versions/ms688296(v=vs.85))
copy the contents of the caller-supplied
[RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_attribute) structure. Therefore, Extension DLLs that export
[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2) need not export
[RadiusExtensionFreeAttributes](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_free_attributes).

This structure is returned by the functions
[GetRequest](https://learn.microsoft.com/previous-versions/ms688263(v=vs.85)) and
[GetResponse](https://learn.microsoft.com/previous-versions/ms688270(v=vs.85)).

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service)

[NPS Extensions Reference](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-reference)

[NPS Extensions Structures](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-structures)

[RADIUS_EXTENSION_CONTROL_BLOCK](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_extension_control_block)

[RadiusExtensionProcess2](https://learn.microsoft.com/windows/desktop/api/authif/nc-authif-pradius_extension_process_2)