## Description

The `Close` method closes a DirectMusic "port", which is a DirectMusic term for a device that sends or receives music data.

## Return value

`Close` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **DMUS_E_ALREADYCLOSED** | Indicates that the port was not open. |

## Remarks

This method closes a DirectMusic "port" that was previously opened by a call to [IDirectMusicSynth::Open](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-open).

When the DirectMusic "port" closes, it automatically releases all instruments and waves that were previously downloaded to the port. However, a good practice for applications is to explicitly free these objects before closing the port.

Avoid confusing the term DirectMusic "port" with a DMus port driver. A DirectMusic port corresponds to a render or capture pin on a DirectMusic filter. For more information about DirectMusic ports, see the description of the **IDirectMusicPort** interface in the Microsoft Windows SDK documentation.

## See also

[IDirectMusicSynth::Open](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-open)