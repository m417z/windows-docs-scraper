## Description

For fields which have an offset (e.g. fields whose location kind indicates LocationMember), the GetOffset method will return the offset from the base address of the containing type (the this pointer) to the data for the field itself. Such offsets are always expressed as unsigned 64-bit values.

If the given field does not have a location which is an offset from the base address of the containing type, the GetOffset method will fail.

## Parameters

### `offset`

The offset of the field data from the base address of the containing type (e.g.: the this pointer) will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

```cpp
ComPtr<IDebugHostField> spField; /* get a field symbol (see EnumerateChildren) */

ULONG64 fieldOffset;
if (SUCCEEDED(spField->GetOffset(&fieldOffset)))
{
    // For locations which have offsets (as indicated by GetLocationKind),
    // fieldOffset will contain the offset of the field from the start
    // of its containing type.
}
```

## See also

[IDebugHostField2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfield2)