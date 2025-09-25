# NPCloseEnum function

## Description

The **NPCloseEnum** function closes an enumeration.

## Parameters

### `hEnum` [in]

Handle obtained from an
[NPOpenEnum](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npopenenum) call.

## Return value

If the function succeeds, it will return WN_SUCCESS. Otherwise, it will return an error code, which can be one of the following:

| Return code | Description |
| --- | --- |
| **WN_NO_NETWORK** | The network is not present. This condition is checked before *hEnum* is tested for validity. |
| **WN_BAD_HANDLE** | *hEnum* is not a valid handle. |