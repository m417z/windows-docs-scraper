# RtlGUIDFromString function

## Description

The **RtlGUIDFromString** routine converts the given Unicode string to a GUID in binary format.

## Parameters

### `GuidString` [in]

Pointer to the buffered Unicode string to be converted to a GUID. The string should be in the following form (including the braces):
{00000000-0000-0000-0000-000000000000}

### `Guid` [out]

Pointer to a caller-supplied variable in which the GUID is returned.

## Return value

If the conversion succeeds, **RtlGUIDFromString** returns STATUS_SUCCESS. Otherwise, no conversion was done.

## See also

[RtlStringFromGUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlstringfromguid)