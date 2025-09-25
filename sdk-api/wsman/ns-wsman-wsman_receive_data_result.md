# WSMAN_RECEIVE_DATA_RESULT structure

## Description

Represents the output data received from a [WSManReceiveShellOutput](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanreceiveshelloutput) method.

## Members

### `streamId`

Represents the **streamId** for which **streamData** is defined.

### `streamData`

Represents the data associated with **streamId**. The data can be stream text, binary content, or XML. For more information about the possible data, see [WSMAN_DATA](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data).

### `commandState`

Specifies the status of the command. If this member is set to **WSMAN_COMMAND_STATE_DONE**, the command should be immediately closed.

### `exitCode`

Defines the exit code of the command. This value is relevant only if the **commandState** member is set to **WSMAN_COMMAND_STATE_DONE**.