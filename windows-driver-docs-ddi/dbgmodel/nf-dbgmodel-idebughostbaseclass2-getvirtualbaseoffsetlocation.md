## Description

The GetVirtualBaseOffsetLocation method retrieves the location of the "offset" of the base class relative to the parent class. It provides information necessary to calculate the virtual table (vtbl or vbtbl) location and the corresponding offset within the base class.

## parameters

### parameter pTableOffset
A pointer to a LONG64 that will receive the offset for the virtual table of the base class relative to the parent class.

### parameter pSlotOffset
A pointer to a LONG64 that will receive the offset within the virtual table.

### parameter pSlotSize
A pointer to an ULONG64 that will receive the size of the slot in the virtual table.

### parameter pSlotIsSigned
A pointer to a boolean that indicates whether the offset read from the slot should be considered a signed or unsigned value.

## Remarks

The location of the vtbl/vbtbl is `(<object> + *pTableOffset)` and the location of the offset within that table is given as `(v[b]tbl + pSlotOffset)`.

## See also

[IDebugHostBaseClass2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostbaseclass2)