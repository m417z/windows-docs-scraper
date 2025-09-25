# CfGetCorrelationVector function

## Description

Allows the sync provider to query the current correlation vector for a given placeholder file. This will either be the one automatically assigned by the platform when the file first opened, or one explicitly assigned via [CfSetCorrelationVector](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetcorrelationvector).

## Parameters

### `FileHandle` [in]

The handle to the placeholder file. The platform properly synchronizes the operation with other active requests. An attribute or no-access handle is sufficient.

### `CorrelationVector` [out]

The correlation vector currently associated with the *FileHandle*.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

The caller must have **READ_DATA** or **WRITE_DAC** access to the placeholder to be hydrated. Otherwise the operation will be failed with **STATUS_CLOUD_FILE_ACCESS_DENIED**.

## See also

[CfSetCorrelationVector](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetcorrelationvector)