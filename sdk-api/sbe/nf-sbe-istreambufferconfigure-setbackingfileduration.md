# IStreamBufferConfigure::SetBackingFileDuration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetBackingFileDuration** method sets the duration of all backing files.

## Parameters

### `dwSeconds` [in]

Specifies the file duration, in seconds. The minimum value is 15.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | The [StreamBufferConfig](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/streambufferconfig-object) object was not initialized. |
| **S_OK** | The method succeeded. |

## Remarks

Before calling this method, call [IStreamBufferInitialize::SetHKEY](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferinitialize-sethkey) to specify a registry key where the information will be stored.

## See also

[IStreamBufferConfigure Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure)