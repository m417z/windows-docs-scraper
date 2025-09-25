# PFND3DDDI_SUBMITWAITFORSYNCOBJECTSTOHWQUEUECB callback function

## Description

A callback to submit a wait command to the hardware queue.

## Parameters

### `hDevice`

A handle to the device.

### `unnamedParam2`

*submitWaitForSyncObjectsToHwQueue* [in]

A pointer to the structure holding information on submitting a wait command to the hardware queue.

## Return value

|Return code|Description|
|--- |--- |
|S_OK|The call was successfully completed.|

This function might also return other HRESULT values.