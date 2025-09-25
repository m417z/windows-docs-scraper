## Description

The AcxObjectBagAddUnicodeString function adds a unicode string to and existing, initialized AcxObjectBag.

## Parameters

### `ObjectBag`

An initialized ObjectBag ACX object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ValueName`

The name of the value that will be used to access the value.

### `Value`

The UNICODE_STRING Value to be added to the ObjectBag.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

This example shows the use of AcxObjectBagAddUnicodeString.

```cpp
    _In_ ACXOBJECTBAG               ObjBag,
    _In_ UNICODE_STRING             FriendlyNameStr,
    _In_ UNICODE_STRING             NameStr
)
{
    PAGED_CODE();

    NTSTATUS status = STATUS_SUCCESS;

    DECLARE_CONST_ACXOBJECTBAG_SYSTEM_PROPERTY_NAME(FriendlyName);
    RETURN_NTSTATUS_IF_FAILED(AcxObjectBagAddUnicodeString(ObjBag, &FriendlyName, &FriendlyNameStr));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)