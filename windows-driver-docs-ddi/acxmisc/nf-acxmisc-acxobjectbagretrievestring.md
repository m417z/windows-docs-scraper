## Description

The AcxObjectBagRetrieveString function retrieves a WDFSTRING object from an existing, initialized AcxObjectBag.

## Parameters

### `ObjectBag`

An initialized ObjectBag ACX object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ValueName`

A ValueName that will be associated with the added string and will be used to retrieve the stored string.

### `Value`

The WDFSTRING object value to be retrieved from the ObjectBag.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

This example shows the use of AcxObjectBagRetrieveString.

```cpp
    status = RtlUnicodeStringInit(&usName, inParams->ValueName);
    if (!NT_SUCCESS(status))
    {
        DrvLogError(g_RecorderLog, FLAG_DDI,
                    "WDFDEVICE %p, RtlUnicodeStringInit(%S) failed, %!STATUS!",
                    m_Device, inParams->ValueName, status);
        goto exit;
    }

    //
    // Set the specified property.
    //
    switch(inParams->ValueType)
    {
    case REG_SZ:
        //
        // Create an empty WDF string to get the value.
        //
        status = WdfStringCreate(nullptr, nullptr, &wsValue);
        if (!NT_SUCCESS(status))
        {
            DrvLogError(g_RecorderLog, FLAG_DDI,
                        "WDFDEVICE %p, WdfStringCreate failed, %!STATUS!",
                        m_Device, status);
            goto exit;
        }

        //
        // Get the string value from bag.
        //
        status = AcxObjectBagRetrieveString(objBag, &usName, wsValue);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)