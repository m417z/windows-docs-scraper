# IStreamBufferDataCounters::GetData

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetData** method returns performance data for the Stream Buffer Engine.

## Parameters

### `pPinData` [in]

Pointer to an [SBE_PIN_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/ns-sbe-sbe_pin_data) structure. The method fills the structure with the current performance data.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IStreamBufferDataCounters Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferdatacounters)