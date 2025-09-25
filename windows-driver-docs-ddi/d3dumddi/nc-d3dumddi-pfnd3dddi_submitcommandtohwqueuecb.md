# PFND3DDDI_SUBMITCOMMANDTOHWQUEUECB callback function

## Description

A callback to submit a command to the hardware queue.

## Parameters

### `hDevice`

A handle to the device.

### `unnamedParam2`

*submitCommandToHwQueue* [in]

A pointer to the structure holding information on submitting a command to the hardware queue.

## Return value

|Return code|Description|
|--|--|
|S_OK|The call was completed successfully.|

This function might also return other HRESULT values.