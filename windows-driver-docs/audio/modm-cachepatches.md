# MODM\_CACHEPATCHES function

WINMM sends the `MODM_CACHEPATCHES` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver to request that the driver cache or uncache the specified patches. This allows internal synthesizer drivers to load the patches that are needed by a client application.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MODM\_CACHEPATCHES** when it calls **modMessage** to process this message.

- *dwUser*
Use this parameter to return instance data to the driver. Drivers that support multiple clients can use this instance data to keep track of the client that is associated with the message.

- *dwParam1*
Specifies a far pointer to a [PATCHARRAY](https://learn.microsoft.com/windows/win32/multimedia/patcharray) array and indicates the patches that must be cached or un-cached.

- *dwParam2*
The high-order word specifies the bank of patches to which the array refers. The low-order word specifies whether the patches must be cached or uncached according to one of the following flags:

  **MIDI\_CACHE\_ALL**. All patches specified in the array must be cached. If the synthesizer cannot cache all the patches, it must not cache any. If the synthesizer fails to cache any patches, it must clear the **PATCHARRAY** and return MMSYSERR\_NOMEM.

  **MIDI\_CACHE\_BESTFIT**. If the driver can cache all the patches specified in the array, it must do so. Otherwise, it must cache as many as it can, alter the **PATCHARRAY** to reflect what it has actually cached, and return MMSYSERR\_NOMEM.

  **MIDI\_CACHE\_QUERY**. The **PATCHARRAY** must be read to determine the patches that the driver has actually cached.

  **MIDI\_UNCACHE**. The patches specified in the array must be uncached and the **PATCHARRAY** must be cleared.

## Return value

The **modMessage** function returns zero if the operation is successful. Otherwise, it returns one of the error messages in the following table.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NOTENABLED** | The driver failed to load or initialize. |
| **MMSYSERR_NOTSUPPORTED** | The function specified in the call to **modMessage** is not supported. |

## Remarks

Patch caching is only supported by internal synthesizer drivers. Drivers for MIDI output ports must return an MMSYSERR\_NOTSUPPORTED error in response to the `MODM_CACHEPATCHES` message. Support for patch caching is optional for internal synthesizer devices. When a driver receives a [**MODM\_GETDEVCAPS**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-getdevcaps) message, it must either set or clear the MIDICAPS\_CACHE bit in the **dwSupport** field of the [MIDIOUTCAPS](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midioutcaps) data structure to indicate support for patch caching.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)

[**MODM\_GETDEVCAPS**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-getdevcaps)

[MIDIOUTCAPS](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midioutcaps)

[PATCHARRAY](https://learn.microsoft.com/windows/win32/multimedia/patcharray)