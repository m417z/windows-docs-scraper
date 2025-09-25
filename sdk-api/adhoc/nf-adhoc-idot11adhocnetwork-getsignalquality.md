# IDot11AdHocNetwork::GetSignalQuality

## Description

Gets the signal quality values associated with the network's radio.

## Parameters

### `puStrengthValue` [out]

The current signal strength. This parameter takes a ULONG value between 0 and *puStrengthMax*.

### `puStrengthMax` [out]

The maximum signal strength value. This parameter takes a ULONG value between 0 and 100. By default, *puStrengthMax* is set to 100.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_OUTOFMEMORY** | The method could not allocate the memory required to perform this operation. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |

## Remarks

Signal strength, in this context, is measured on a linear scale. When *puStrengthMax* is set to the default value of 100, *puStrengthValue* represents the percentage of the maximum signal strength currently used for transmission.

## See also

[IDot11AdHocNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetwork)