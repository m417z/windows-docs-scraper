# PIBIO_ENGINE_IDENTIFY_ALL_FN callback function

## Description

Called by the Windows Biometric Framework to determine the identities of any people who are currently in camera frame.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `PresenceCount` [out]

Address of a variable that receives the number of presences detected by the function.

### `PresenceArray` [out]

Address of a variable that receives a pointer to an array of [WINBIO_PRESENCE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-presence) elements.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_some_error** | Any error code will cause the Biometric Service to log the error and ignore the camera frame. |

## Remarks

The biometric service calls this method after it sends a new frame of data to the engine adapter.

After processing the data frame, this function should return one [WINBIO_PRESENCE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-presence) element for each presence detected in the data frame.

In the event that the **EngineAdapterIdentifyAll** function can’t find any faces in frame, it returns an **HRESULT** of **S_OK** and sets the *PresenceCount* and *PresenceArray* return parameters to zero and **NULL**, respectively. In other words, a frame that doesn’t contain any human presences is not an error condition.

The only time **EngineAdapterIdentifyAll** should return an **HRESULT** other than **S_OK** is if it doesn’t want the bio service to use the frame to update the Presence Monitor state. This should be a rare occurrence.
The engine adapter is responsible for allocating the array of [WINBIO_PRESENCE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-presence) elements it returns in the *PresenceArray* parameter. It must allocate this memory from the process heap by using the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) function. After the array is created, it becomes the property of the Windows Biometric Framework. Because the Framework deallocates this memory after using it, your engine adapter must not attempt to deallocate the array or save a pointer to it. Failure to follow this rule will lead to heap corruption and possible crashes of the biometric service.

The values of the individual [WINBIO_PRESENCE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-presence) items in the *PresenceArray* will determine the events generated for client applications. See the discussion of the **WINBIO_PRESENCE** structure for details.