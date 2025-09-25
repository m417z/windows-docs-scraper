# IBackgroundCopyJob5::GetProperty

## Description

A generic method for getting BITS job properties.

## Parameters

### `PropertyId` [in]

The ID of the property that is being obtained specified as a [BITS_JOB_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/bits5_0/ne-bits5_0-bits_job_property_id) enum value.

### `PropertyValue` [out]

The property value returned as a BITS_JOB_PROPERTY_VALUE union.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## See also

[IBackgroundCopyJob5](https://learn.microsoft.com/windows/desktop/api/bits5_0/nn-bits5_0-ibackgroundcopyjob5)

[IBackgroundCopyJob5::SetProperty](https://learn.microsoft.com/windows/desktop/api/bits5_0/nf-bits5_0-ibackgroundcopyjob5-setproperty)