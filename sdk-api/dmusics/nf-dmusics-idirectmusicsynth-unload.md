# IDirectMusicSynth::Unload

## Description

The `Unload` method unloads a DLS resource (waveform or articulation data for a MIDI instrument) that was previously downloaded by a call to [IDirectMusicSynth::Download](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-download).

## Parameters

### `hDownload`

Handle to the DLS resource, which was obtained from a previous call to the **IDirectMusicSynth::Download** method. If the *lpFreeHandle* parameter below is non-**NULL**, the synthesizer passes this handle as the first parameter to the *lpFreeHandle* callback routine.

### `lpFreeHandle`

Pointer to a callback routine that will be called when the memory containing the DLS resource is no longer in use. If the original call to **IDirectMusicSynth::Download** returned **FALSE** in *pbFree*, this means that the synthesizer continued accessing the caller-allocated memory in the download chunk after the return from **Download**. If so, the synthesizer notifies the caller as soon as the memory can be freed, but this might occur later than the return from `Unload` because the DLS resource might be currently in use. The callback function takes two handles as call parameters. The first of these two handles is the *hDownload* parameter (see above), and the second is the *hUserData* parameter (see below).

### `hUserData`

Pointer to user data, which is passed as the second parameter to the *lpFreeHandle* callback function above. The meaning of this value is known only to the caller, but it is typically a pointer to context information describing the state of the memory that is to be freed.

## Return value

`Unload` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Indicates that the method is unable to unload data (*hDownload* probably invalid). |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth is not open or not properly configured. |

## Remarks

When the caller downloads a DLS resource to the synthesizer by calling **IDirectMusicSynth::Download**, the synthesizer has the option of either making its own copy of the DLS resource or continuing to use the caller's copy of the DLS resource. The **Download** method specifies one of these options by the value that it outputs through its *pbFree* parameter:

* **pbFree*=**TRUE** if the synthesizer makes its own copy. In this case, the caller can free the DLS memory on return from **Download**. Also, the caller can specify the values for the `Unload` method's *lpFreeHandle* and *hUserData* parameters as **NULL**.
* **pbFree*=**FALSE** if the synthesizer keeps a pointer to the caller's copy. In this case, the caller must maintain its allocation of the memory containing the DLS resource until the synthesizer has finished using that memory.

In the latter case, the caller must not release the memory for the DLS resource immediately on return from the `Unload` call because the synthesizer might still be in the process of rendering a note that uses the DLS resource. Instead, the caller must wait for the synthesizer to call the *lpFreeHandle* callback routine, which the synthesizer will do as soon as the note finishes and the memory is no longer needed.

For more information, see the descriptions of the **IDirectMusic** and **IDirectMusicPort** interfaces and the **IDirectMusicPort::UnloadInstrument** method in the Microsoft Windows SDK documentation.

## See also

[IDirectMusicSynth::Download](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-download)