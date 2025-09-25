# IDVBTuningSpace::get_SystemType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SystemType** method retrieves the system type.

## Parameters

### `SysType` [out]

Pointer to a variable of type [DVBSystemType](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/dvbsystemtype) that receives the system type.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IDVBTuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-idvbtuningspace)