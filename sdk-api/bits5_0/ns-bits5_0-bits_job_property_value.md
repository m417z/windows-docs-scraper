## Description

Provides the property value of the BITS job based on the value of the [BITS_JOB_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/bits5_0/ne-bits5_0-bits_job_property_id) enumeration.

## Members

### `Dword`

This value is returned when using the enum property ID
**BITS_JOB_PROPERTY_ID_COST_FLAGS** and is applied as the
[transfer policy](https://learn.microsoft.com/windows/desktop/api/bits5_0/ne-bits5_0-bits_job_transfer_policy) on the BITS job.

This value is also used when using the **BITS_JOB_PROPERTY_MINIMUM_NOTIFICATION_INTERVAL_MS** to specify the minimum notification interval.

### `ClsID`

This value is returned when using the enum property ID
**BITS_JOB_PROPERTY_NOTIFICATION_CLSID** and represents the CLSID of the callback object
to register with the BITS job.

### `Enable`

This value is returned when using the enum property ID
**BITS_JOB_PROPERTY_DYNAMIC_CONTENT** to specify whether the BITS job has dynamic
content. This value is also returned when using the enum property ID
**BITS_JOB_PROPERTY_HIGH_PERFORMANCE** to specify whether to mark the BITS job as an optimized download.

This value is also used when using the **BITS_JOB_PROPERTY_ON_DEMAND_MODE** to specify whether the BITS job is in on demand or not.

### `Uint64`

This value is returned when using the enum property ID
**BITS_JOB_PROPERTY_MAX_DOWNLOAD_SIZE** to represent the maximum allowed download size
of an optimized download.

### `Target`

This value is returned when using the enum property ID **BITS_JOB_PROPERTY_USE_STORED_CREDENTIALS** to represent the intranet authentication target which is permitted to use stored credentials.

## See also

[BITS_JOB_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/bits5_0/ne-bits5_0-bits_job_property_id)

[BITS_JOB_TRANSFER_POLICY](https://learn.microsoft.com/windows/desktop/api/bits5_0/ne-bits5_0-bits_job_transfer_policy)