# IMFMediaSession::ClearTopologies

## Description

Clears all of the presentations that are queued for playback in the Media Session.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The operation cannot be performed in the Media Session's current state. |
| **MF_E_SHUTDOWN** | The Media Session has been shut down. |

## Remarks

This method is asynchronous. When the operation completes, the Media Session sends an [MESessionTopologiesCleared](https://learn.microsoft.com/windows/desktop/medfound/mesessiontopologiescleared) event.

This method does not clear the current topology; it only removes topologies that are placed in the queue, waiting for playback. To remove the current topology, call [IMFMediaSession::SetTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-settopology) with the **MFSESSION_SETTOPOLOGY_CLEAR_CURRENT** flag.

## See also

[IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession)