# IMSVidAnalogTuner2::get_TunerModes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **get_TunerModes** method retrieves a flag value that indicates which modes the tuner supports, such as TV or FM.

## Parameters

### `Modes` [out]

Pointer to a variable that receives the modes flag. Possible values are the sum of one or more of the values in the following table.

| Value | Description |
| --- | --- |
| 0x0000 | Default tuner mode. |
| 0x0001 | TV tuner mode. |
| 0x0002 | FM radio tuner mode. |
| 0x0004 | AM radio tuner mode. |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | Success. |

## See also

[IMSVidAnalogTuner2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidanalogtuner2)