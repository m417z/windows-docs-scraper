# IDirectMusicSynth::GetFormat

## Description

The `GetFormat` method retrieves information about the wave format.

## Parameters

### `pWaveFormatEx`

Pointer to a caller-allocated [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) structure into which the method writes information about the format. This value can be **NULL**. For more information, see the following Remarks section.

### `pdwWaveFormatExSize`

Pointer to a caller-allocated DWORD variable specifying the size in bytes of the structure that *pWaveFormatEx* points to. For more information, see the following Remarks section.

## Return value

`GetFormat` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Indicates that one of the pointers is not valid. |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth is not open or is not properly configured. |

## Remarks

The WAVEFORMATEX structure can have a variable length that depends on the details of the format. Therefore, before retrieving the format description, an application will first query the **IDirectMusicSynth** object for the size of the format by calling this method and specifying **NULL** for the *pWaveFormatEx* parameter. In this case, the synth should return the size of the structure in the *pdwWaveFormatExSize* parameter. The application can then allocate sufficient memory and call `IDirectMusicSynth::GetFormat` again to retrieve the format description.

If the *pWaveFormatEx* parameter is not **NULL**, DirectMusic writes, at most, *pdwWaveFormatExSize* bytes to *pWaveFormatEx*.

For more information, see the description of the **IDirectMusicPort** interface and **IDirectMusicPort::GetFormat** method in the Microsoft Windows SDK documentation.

## See also

[WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex)