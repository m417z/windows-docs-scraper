# IMFMediaSession::SetTopology

## Description

Sets a topology on the Media Session.

## Parameters

### `dwSetTopologyFlags` [in]

Bitwise **OR** of zero or more flags from the [MFSESSION_SETTOPOLOGY_FLAGS](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfsession_settopology_flags) enumeration.

### `pTopology` [in]

Pointer to the topology object's [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The operation cannot be performed in the Media Session's current state. |
| **MF_E_SHUTDOWN** | The Media Session has been shut down. |
| **MF_E_TOPO_INVALID_TIME_ATTRIBUTES** | The topology has invalid values for one or more of the following attributes:<br><br>* [MF_TOPONODE_MEDIASTART](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-mediastart-attribute)<br>* [MF_TOPONODE_MEDIASTOP](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-mediastop-attribute)<br>* [MF_TOPOLOGY_PROJECTSTART](https://learn.microsoft.com/windows/desktop/medfound/mf-topology-projectstart-attribute)<br>* [MF_TOPOLOGY_PROJECTSTOP](https://learn.microsoft.com/windows/desktop/medfound/mf-topology-projectstop-attribute) |
| **NS_E_DRM_DEBUGGING_NOT_ALLOWED** | Protected content cannot be played while debugging. |

## Remarks

If *pTopology* is a full topology, set the **MFSESSION_SETTOPOLOGY_NORESOLUTION** flag in the *dwSetTopologyFlags* parameter. Otherwise, the topology is assumed to be a partial topology. The Media Session uses the topology loader to resolve a partial topology into a full topology.

If the Media Session is currently paused or stopped, the **SetTopology** method does not take effect until the next call to [IMFMediaSession::Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-start).

If the Media Session is currently running, or on the next call to [Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-start), the **SetTopology** method does the following:

* If the **MFSESSION_SETTOPOLOGY_IMMEDIATE** flag is set in *dwSetTopologyFlags*, the Media Session ends the current presentation immediately, clears all pending topologies, and uses *pTopology* to start a new presentation.
* Otherwise, the Media Session queues *pTopology* and starts the new presentation when the current presentation has completed. If there is no current presentation, the new presentation starts immediately.
* Starting in Windows 7, you can also specify the **MFSESSION_SETTOPOLOGY_CLEAR_CURRENT** flag to clear the current topology but leave any other pending topologies on the queue.

This method is asynchronous. If the method returns S_OK, the Media Session sends an [MESessionTopologySet](https://learn.microsoft.com/windows/desktop/medfound/mesessiontopologyset) event when the operation completes.
If the Media Session is currently paused to stopped, the Media Session does not send the MESessionTopologySet event until the next call to [IMFMediaSession::Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-start)

## See also

[IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession)