# ICreateTypeInfo::SetAlignment

## Description

Specifies the data alignment for an item of TYPEKIND=TKIND_RECORD.

## Parameters

### `cbAlignment` [in]

Alignment method for the type. A value of 0 indicates alignment on the 64K boundary; 1 indicates no special alignment. For other values, n indicates alignment on byte *n*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_ACCESSDENIED** | Cannot write to the destination. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_INVALIDSTATE** | The state of the type library is not valid for this operation. |

## Remarks

The alignment is the minimum of the natural alignment (for example, byte data on byte boundaries, word data on word boundaries, and so on), and the alignment denoted by *cbAlignment*.

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)