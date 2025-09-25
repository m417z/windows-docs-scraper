# CoFileTimeToDosDateTime function

## Description

Converts a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) into MS-DOS date and time values.

**Note** This function is provided for compatibility with 16-bit Windows.

## Parameters

### `lpFileTime` [in]

A pointer to the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

### `lpDosDate` [out]

Receives the MS-DOS date.

### `lpDosTime` [out]

Receives the MS-DOS time.

## Return value

If the function succeeds, the return value is **TRUE**; otherwise, it is **FALSE**.

## See also

[CoDosDateTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-codosdatetimetofiletime)

[CoFileTimeNow](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofiletimenow)