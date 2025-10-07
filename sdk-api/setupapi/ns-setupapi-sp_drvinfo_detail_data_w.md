# SP_DRVINFO_DETAIL_DATA_W structure

## Description

An SP_DRVINFO_DETAIL_DATA structure contains detailed information about a particular driver information structure.

## Members

### `cbSize`

The size, in bytes, of the SP_DRVINFO_DETAIL_DATA structure.

### `InfDate`

Date of the INF file for this driver.

### `CompatIDsOffset`

The offset, in characters, from the beginning of the **HardwareID** buffer where the CompatIDs list begins.

This value can also be used to determine whether there is a [hardware ID](https://learn.microsoft.com/windows-hardware/drivers/install/hardware-ids) that precedes the CompatIDs list. If this value is greater than 1, the first string in the **HardwareID** buffer is the hardware ID. If this value is less than or equal to 1, there is no hardware ID.

### `CompatIDsLength`

The length, in characters, of the CompatIDs list starting at offset **CompatIDsOffset** from the beginning of the **HardwareID** buffer.

If **CompatIDsLength** is nonzero, the CompatIDs list contains one or more NULL-terminated strings with an additional NULL character at the end of the list.

If **CompatIDsLength** is zero, the CompatIDs list is empty. In that case, there is no additional NULL character at the end of the list.

### `Reserved`

Reserved. For internal use only.

### `SectionName`

A NULL-terminated string that contains the name of the [INF DDInstall section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-section) for this driver. This must be the basic *DDInstall* section name, such as **InstallSec**, without any OS/architecture-specific extensions.

### `InfFileName`

A NULL-terminated string that contains the full-qualified name of the INF file for this driver.

### `DrvDescription`

A NULL-terminated string that describes the driver.

### `HardwareID`

A buffer that contains a list of IDs (a single [hardware ID](https://learn.microsoft.com/windows-hardware/drivers/install/hardware-ids) followed by a list of [compatible IDs](https://learn.microsoft.com/windows-hardware/drivers/install/compatible-ids)). These IDs correspond to the hardware ID and compatible IDs in the [INF Models section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-models-section).

Each ID in the list is a NULL-terminated string.

If the hardware ID exists (that is, if **CompatIDsOffset** is greater than one), this single NULL-terminated string is found at the beginning of the buffer.

If the CompatIDs list is not empty (that is, if **CompatIDsLength** is not zero), the CompatIDs list starts at offset **CompatIDsOffset** from the beginning of this buffer, and is terminated with an additional NULL character at the end of the list.

## Remarks

The [hardware ID](https://learn.microsoft.com/windows-hardware/drivers/install/hardware-ids) and [compatible IDs](https://learn.microsoft.com/windows-hardware/drivers/install/compatible-ids) for a device are specified in the [INF Models section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-models-section) in the following order:

* The first ID (if specified) is the hardware ID for the device.
* The remaining IDs (if specified) are compatible IDs for the device.

When you parse the **HardwareID** buffer, you must ensure that you correctly determine the end of the data in the buffer. Be aware that the buffer is not necessarily double NULL terminated.

For example, depending on how the list of [hardware ID](https://learn.microsoft.com/windows-hardware/drivers/install/hardware-ids) and [compatible IDs](https://learn.microsoft.com/windows-hardware/drivers/install/compatible-ids) are specified in the [INF Models section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-models-section), the **HardwareID** buffer can resemble any of the following:

* \0
* \<HWID>\0
* \<HWID>\0\<COMPATID_1>\0...\<COMPATID_N>\0\0
* \0\<COMPATID_1>\0...\<COMPATID_N>\0\0

An algorithm to correctly parse this buffer must use the **CompatIDsOffset** and **CompatIDsLength** fields to extract the [hardware ID](https://learn.microsoft.com/windows-hardware/drivers/install/hardware-ids) and [compatible IDs](https://learn.microsoft.com/windows-hardware/drivers/install/compatible-ids), as shown in the following code example:

```
// parse the hardware ID, if it exists
if (CompatIDsOffset > 1)
{
    // Parse for hardware ID from index 0.
    // This is a single NULL-terminated string
}
 // Parse the compatible IDs, if they exist
if (CompatIDsLength > 0)
{
    // Parse for list of compatible IDs from CompatIDsOffset.
    // This is a double NULL-terminated list of strings (i.e. MULTI-SZ)
}
```

> [!NOTE]
> The setupapi.h header defines SP_DRVINFO_DETAIL_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Compatible IDs](https://learn.microsoft.com/windows-hardware/drivers/install/compatible-ids)

[Hardware ID](https://learn.microsoft.com/windows-hardware/drivers/install/hardware-ids)

[INF DDInstall Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-section)

[INF Models Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-models-section)

[SetupDiGetDriverInfoDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdriverinfodetaila)