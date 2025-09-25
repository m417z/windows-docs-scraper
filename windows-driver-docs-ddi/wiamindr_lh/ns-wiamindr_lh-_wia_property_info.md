## Description

The **WIA_PROPERTY_INFO** structure is used to store default access and valid value information for an item property of arbitrary type.

## Members

### `lAccessFlags`

Specifies the access and property attribute flags for a property. For more information, see [Property Attributes](https://learn.microsoft.com/windows/win32/wia/-wia-property-attributes).

### `vt`

Specifies the variant data type for the property. This member, which can be one of the following, controls which structure member of the **ValidValunion** is valid:

- VT_UI1

- VT_UI2

- VT_UI4

- VT_I2

- VT_I4

- VT_R4

- VT_R8

- VT_CLSID

- VT_BSTR

For more information, see [PROPVARIANT](https://learn.microsoft.com/windows/win32/api/propidl/ns-propidl-propvariant).

### `ValidVal`

### `ValidVal.Range`

A structure that is filled when the property's valid values are specified by a range of integer values.

### `ValidVal.Range.Min`

The minimum value of the property.

### `ValidVal.Range.Nom`

The property's nominal value.

### `ValidVal.Range.Max`

The maximum value of the property.

### `ValidVal.Range.Inc`

The increment value that can be used.

### `ValidVal.RangeFloat`

A structure that is filled when the property's valid values are specified by a range of floating-point values and the property type is a **float** or **double**.

### `ValidVal.RangeFloat.Min`

The minimum value of the property.

### `ValidVal.RangeFloat.Nom`

The property's nominal value.

### `ValidVal.RangeFloat.Max`

The maximum value of the property.

### `ValidVal.RangeFloat.Inc`

The increment value that can be used.

### `ValidVal.List`

A structure that is filled when the property's valid values are specified by a list of integer values.

### `ValidVal.List.cNumList`

The number of elements in the array of valid values to which **pList** points.

### `ValidVal.List.Nom`

The nominal value of the property.

### `ValidVal.List.pList`

An array of valid values the property can be set to.

### `ValidVal.ListFloat`

A structure that is filled when the property's valid values are specified by a list of floating-point values.

### `ValidVal.ListFloat.cNumList`

The number of elements in the array of valid values to which **pList** points.

### `ValidVal.ListFloat.Nom`

The nominal value of the property.

### `ValidVal.ListFloat.pList`

An array of valid values the property can be set to.

### `ValidVal.ListGuid`

A structure that is filled when the property's valid values are specified by a list of GUIDs.

### `ValidVal.ListGuid.cNumList`

The number of elements in the array of valid values to which **pList** points.

### `ValidVal.ListGuid.Nom`

The nominal value of the property.

### `ValidVal.ListGuid.pList`

An array of valid values the property can be set to.

### `ValidVal.ListBStr`

A structure that is filled when the property's valid values are specified by a list of strings.

### `ValidVal.ListBStr.cNumList`

The number of elements in the array of valid values to which **pList** points.

### `ValidVal.ListBStr.Nom`

The nominal value of the property.

### `ValidVal.ListBStr.pList`

An array of valid values the property can be set to.

### `ValidVal.Flag`

A structure that is filled when the property's valid values are specified by a bitset of flags.

### `ValidVal.Flag.Nom`

The nominal value of the property.

### `ValidVal.Flag.ValidBits`

A mask indicating which bit values can be set. This member should be a bitwise OR of all possible user-defined flag values.

### `ValidVal.None`

A structure that is filled when the property's valid values are not given in a list, range, or bitset. This structure contains a member named **Dummy**, which indicates the property is of type NONE.

### `ValidVal.None.Dummy`

## Remarks

The **WIA_PROPERTY_INFO** is used by the minidriver to store information about a property of arbitrary type. This structure is also used by the **wiasSetItemPropAttribs** to set a property's valid values. The **lAccessFlags** member controls whether access to a property is read-only or read/write. This member also conveys information about the set of valid values for a property when they are defined by a list of values, a range of values, or a bitset of flags. The **vt** member contains information about the type of the property. Both members should be used to determine which member of the **ValidValunion** can be accessed.

For example, for a read/write property of type **long**, whose valid values are integers in the range -128 to 127, and whose nominal value is 0, **lAccessFlags** would be set to WIA_PROP_RW | WIA_PROP_RANGE, and **vt** would be set to VT_I4. **Range.Min** would be set to -128, **Range.Max** would be set to 127, and **Range.Inc** would be set to 1. **Range.Nom** would be set to 0.

For a different property whose valid values are defined by a list of three GUID values, **lAccessFlags** would have its WIA_PROP_LIST bit set, and **vt** would be set to VT_CLSID. **ListGuid.cNumList** would be set to 3, and the three GUIDs are **ListGuid.pList**[0], **ListGuid.pList**[1], and **ListGuid.pList**[2].

A property whose valid values are defined by a bitset of the values 0x01, 0x02, 0x04, and 0x08 would have the WIA_PROP_FLAG bit set in **lAccessFlags**, and **vt** would be set to VT_UI4. For such a property, the value stored in **Flag.ValidBits** would be 0x0F, the bitwise OR of the four flag values previously mentioned.

The following examples show how to use array data with WIA_PROPERTY_INFO and how to call [wiasWriteMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritemultiple) to set your property values.

Initialization might look like the following example:

```cpp
// Initialize WIA_IPA_ITEM_TIME (NONE)
  g_pszItemDefaults[13]              = WIA_IPA_ITEM_TIME_STR;
  g_piItemDefaults [13]              = WIA_IPA_ITEM_TIME;
  g_pvItemDefaults [13].cai.celems   = MyNumberOfElements;
  g_pvItemDefaults [13].cai.pelems   = PointerToMyArray;
  g_pvItemDefaults [13].vt           = VT_VECTOR|VT_UI2; // MyArray is an array of DWORD values
  g_psItemDefaults [13].ulKind       = PRSPEC_PROPID;
  g_psItemDefaults [13].propid       = g_piItemDefaults [13];
  g_wpiItemDefaults[13].lAccessFlags = WIA_PROP_READ|WIA_PROP_NONE;
  g_wpiItemDefaults[13].vt           = g_pvItemDefaults [13].vt;
```

At run time, changing the value with **wiasWriteMultiple** might look like the following example:

```cpp
PROPVARIANT propVar;
PROPSPEC    propSpec;
PropVariantInit(&propVar);
propVar.vt          = VT_VECTOR | VT_UI2;
propVar.caui.cElems = sizeof(SYSTEMTIME) / sizeof(WORD);
propVar.caui.pElems = (WORD *) &CurrentTimeStruct;
propSpec.ulKind     = PRSPEC_PROPID;
propSpec.propid     = WIA_IPA_ITEM_TIME;
hr                  = wiasWriteMultiple(pWiasContext, 1, &propSpec, &propVar);
```

WIA uses the COM [PROPVARIANT](https://learn.microsoft.com/windows/win32/api/propidl/ns-propidl-propvariant) type, [VARIANT](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-variant), so the default is VT_VECTOR, and not VT_ARRAY (which is also supported).

## See also

[wiasSetItemPropAttribs](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetitempropattribs)