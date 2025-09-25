# CoFileTimeNow function

## Description

Returns the current time as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

**Note** This function is provided for compatibility with 16-bit Windows.

## Parameters

### `lpFileTime` [out]

A pointer to the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the current time.

## Return value

This function returns S_OK to indicate success.

## See also

[CoDosDateTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-codosdatetimetofiletime)

[CoFileTimeToDosDateTime](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cofiletimetodosdatetime)