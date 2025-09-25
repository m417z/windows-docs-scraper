## Description

The **AcxDataFormatGetSubFormat** function gets the subformat for the specified data format.

## Parameters

### `DataFormat` [in]

The data format for which to retrieve the subformat.

## Return value

Returns a GUID value representing the subformat for the specified *DataFormat*.

## Remarks

Specifies the subformat of a general format type. The data subformats that are currently supported can be found in the KSDATAFORMAT_SUBTYPE_XXX symbolic constants in the ksmedia.h header file that is included in the WDK. Major formats that do not support subformats should use the KSDATAFORMAT_SUBTYPE_NONE value for this member.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)
- [Stream Categories](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-categories)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)