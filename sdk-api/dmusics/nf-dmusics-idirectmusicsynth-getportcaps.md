# IDirectMusicSynth::GetPortCaps

## Description

The `GetPortCaps` method retrieves the capabilities of a DirectMusic "port", which is a DirectMusic term for a device that sends or receives music data.

## Parameters

### `pCaps`

Pointer to a DMUS_PORTCAPS structure (described in the Microsoft Windows SDK documentation). The method writes the capabilities of the DirectMusic "port" into this structure.

## Return value

`GetPortCaps` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Indicates a bad *pCaps* pointer. |

## Remarks

When an application enumerates the available DirectMusic "ports" with a call to **IDirectMusic::EnumPort** (described in the Windows SDK documentation), DirectMusic calls each registered device's `GetPortCaps` method.

This means that the additional overhead of creating and initializing the synthesizer occurs with this call. It is a good idea to keep the overhead of simply creating a synthesizer to a minimum, because there is a chance that it is being created only so that its capabilities can be obtained, and then it will be released.

Avoid confusing the term DirectMusic "port" with a DMus port driver. A DirectMusic port corresponds to a render or capture pin on a DirectMusic filter. For more information about DirectMusic ports, see the description of the **IDirectMusicPort** interface in the Windows SDK documentation.