## Description

The **AcxDataFormatGetMajorFormat** function gets the major format for the specified data format.

## Parameters

### `DataFormat` [in]

The data format for which to retrieve the major format.

## Return value

Returns a GUID value representing the major format for the specified *DataFormat*.

## Remarks

Specifies the general format type. The data formats that are currently supported can be found in the KSDATAFORMAT_TYPE_XXX symbolic constants in the ksmedia.h header file that is included in the Windows Driver Kit (WDK). A data stream that has no particular format should use KSDATAFORMAT_TYPE_STREAM (defined in ks.h) as the value for its major format.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)
- [Stream Categories](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-categories)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)