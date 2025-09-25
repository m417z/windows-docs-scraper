# RtlStringFromGUID function

## Description

The **RtlStringFromGUID** routine converts a given GUID from binary format into a Unicode string.

## Parameters

### `Guid` [in]

Specifies the binary-format GUID to convert.

### `GuidString` [out]

Pointer to a caller-supplied variable in which a pointer to the converted GUID string is returned. **RtlStringFromGUID** allocates the buffer space for the string, which the caller must free by calling **RtlFreeUnicodeString**. The returned string is in the form `{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}`, including the prepended and appended braces.

## Return value

If the conversion succeeds, **RtlStringFromGUID** returns STATUS_SUCCESS. Otherwise, no storage was allocated, nor was the conversion performed.

## See also

[RtlGUIDFromString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlguidfromstring)