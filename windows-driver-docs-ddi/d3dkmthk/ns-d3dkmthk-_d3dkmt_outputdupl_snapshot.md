# D3DKMT_OUTPUTDUPL_SNAPSHOT structure

## Description

The **D3DKMT_OUTPUTDUPL_SNAPSHOT** structure provides information on the current processes in which output duplication is occurring.

## Members

### `Size`

[in/out] The size, in bytes, of the entire structure.

### `SessionProcessCount`

[out] The number of processes in this session that are currently duplicating output. The value of **NumOutputDuplContexts** specifies the maximum possible number of processes.

### `SessionActiveConnectionsCount`

[out] The total number of active contexts in this session. The value may be more than the number of active contexts in the 2-D array, which are per adapter.

### `NumVidPnSources`

[out] The number of video present network (VidPN) sources.

### `NumOutputDuplContexts`

[out] The number of contexts in which output duplication is occurring.

### `Padding`

Padding.

### `OutputDuplDebugInfos[0]`

Reserved for system use. Set to zero.