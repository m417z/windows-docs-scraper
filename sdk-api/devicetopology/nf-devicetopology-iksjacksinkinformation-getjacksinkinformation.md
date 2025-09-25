# IKsJackSinkInformation::GetJackSinkInformation

## Description

The **GetJackSinkInformation** method retrieves the sink information for the specified jack.

## Parameters

### `pJackSinkInformation` [out]

Pointer to a caller-allocated buffer that receives the sink information of the jack in a [KSJACK_SINK_INFORMATION](https://learn.microsoft.com/windows/win32/api/devicetopology/ns-devicetopology-ksjack_sink_information) structure. The buffer size must be at least `sizeof(KSJACK_SINK_INFORMATION)`.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nJack* is not a valid jack index. |
| **E_POINTER** | Pointer *pDescription* is **NULL**. |

## See also

[IKsJackSinkInformation](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksjacksinkinformation)