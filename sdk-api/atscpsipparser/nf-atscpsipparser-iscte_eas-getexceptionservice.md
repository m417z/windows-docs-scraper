# ISCTE_EAS::GetExceptionService

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetExceptionService** method returns information about an exception service.

## Parameters

### `bIndex` [in]

Zero-based index of the exception service to retrieve. Call [ISCTE_EAS::GetExceptionCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-getexceptioncount) to get the number of exception services.

### `pbIBRef` [out]

Receives the in_band_reference flag.

### `pwFirst` [out]

If the in_band_reference flag is **TRUE**, receives the exception_major_channel_number field. Otherwise, receives the exception_OOB_source_ID field.

### `pwSecond` [out]

If the in_band_reference flag is **TRUE**, receives the exception_minor_channel_number field. Otherwise, the value is undefined and this parameter should be ignored.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of range. |
| **MPEG2_E_UNINITIALIZED** | The [ISCTE_EAS::Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-initialize) method was not called. |
| **S_OK** | The method succeeded. |

## See also

[ISCTE_EAS Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iscte_eas)