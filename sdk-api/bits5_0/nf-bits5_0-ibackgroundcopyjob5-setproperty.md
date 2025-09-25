# IBackgroundCopyJob5::SetProperty

## Description

A generic method for setting BITS job properties.

## Parameters

### `PropertyId` [in]

The ID of the property that is being set specified as a [BITS_JOB_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/bits5_0/ne-bits5_0-bits_job_property_id) enum value.

### `PropertyValue` [in]

The value of the property that is being set. In order to hold a value whose type is appropriate to the property, this value is specified via the [BITS_JOB_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/bits5_0/ns-bits5_0-bits_job_property_value) union that is composed of all the known property types.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## See also

[IBackgroundCopyJob5](https://learn.microsoft.com/windows/desktop/api/bits5_0/nn-bits5_0-ibackgroundcopyjob5)

**IBackgroundCopyJob5::GetProperty**